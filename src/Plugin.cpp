#include "DoFRenderer.h"
#include "DoFUI.h"
#include "HotkeyInput.h"
#include "Settings.h"

#include <detours.h>

namespace
{
	std::atomic_bool firstMainPathLogged{ false };

	void SetupLogging()
	{
		auto directory = SKSE::log::log_directory();
		if (!directory) {
			return;
		}
		*directory /= "CinematicDoFStandalone.log";
		auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(directory->string(), true);
		auto logger = std::make_shared<spdlog::logger>("global", std::move(sink));
		logger->set_level(spdlog::level::info);
		logger->flush_on(spdlog::level::info);
		spdlog::set_default_logger(std::move(logger));
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
	}

	struct MainPostProcessingHook
	{
		static void Thunk(
			RE::ImageSpaceManager* a_imageSpaceManager,
			std::uint32_t a_unk1,
			RE::RENDER_TARGET a_target,
			void* a_unk2,
			bool a_unk3)
		{
			if (!firstMainPathLogged.exchange(true)) {
				spdlog::info("Entered main post-processing path");
			}
			auto& renderer = CDoF::DoFRenderer::GetSingleton();
			renderer.ApplyBeforePostProcessing();
			function(a_imageSpaceManager, a_unk1, a_target, a_unk2, a_unk3);
			renderer.ApplyAfterPostProcessing(a_target);
		}
		static inline REL::Relocation<decltype(Thunk)> function;
	};

	struct RenderTransparencyHook
	{
		using Function = void (*)(RE::BSShaderAccumulator*, std::uint32_t);

		static void Thunk(RE::BSShaderAccumulator* a_accumulator, std::uint32_t a_renderFlags)
		{
			auto& renderer = CDoF::DoFRenderer::GetSingleton();
			renderer.CaptureTransparencyBefore();
			function(a_accumulator, a_renderFlags);
			renderer.CaptureTransparencyAfter();
		}

		static inline Function function{};
	};

	bool InstallTransparencyHook()
	{
		REL::Relocation<std::uintptr_t> renderTransparency{ REL::RelocationID(99940, 106585) };
		RenderTransparencyHook::function = reinterpret_cast<RenderTransparencyHook::Function>(
			renderTransparency.address());

		if (DetourTransactionBegin() != NO_ERROR) {
			return false;
		}
		if (DetourUpdateThread(GetCurrentThread()) != NO_ERROR ||
			DetourAttach(
				reinterpret_cast<PVOID*>(std::addressof(RenderTransparencyHook::function)),
				reinterpret_cast<PVOID>(RenderTransparencyHook::Thunk)) != NO_ERROR) {
			DetourTransactionAbort();
			return false;
		}
		if (DetourTransactionCommit() != NO_ERROR) {
			return false;
		}

		spdlog::info("Installed transparency-pass diagnostic hook at 0x{:X}", renderTransparency.address());
		return true;
	}

	void InstallHooks()
	{
		static std::atomic_bool installed{ false };
		if (installed.exchange(true)) {
			return;
		}

		static REL::Relocation<std::uintptr_t> mainPostProcessing{
			REL::RelocationID(100430, 107148),
			static_cast<std::ptrdiff_t>(REL::VariantOffset(0x1F0, 0x1E7, 0x206).offset())
		};
		MainPostProcessingHook::function = SKSE::GetTrampoline().write_call<5>(
			mainPostProcessing.address(),
			MainPostProcessingHook::Thunk);

		spdlog::info("Installed main post-processing hook at 0x{:X}", mainPostProcessing.address());
		if (!InstallTransparencyHook()) {
			spdlog::critical("Failed to install transparency-pass diagnostic hook");
		}
	}

	void MessageHandler(SKSE::MessagingInterface::Message* a_message)
	{
		if (!a_message) {
			return;
		}
		if (a_message->type == SKSE::MessagingInterface::kPostLoad) {
			CDoF::UI::TryRegister();
		} else if (a_message->type == SKSE::MessagingInterface::kDataLoaded) {
			CDoF::HotkeyInput::Register();
			// Install at DataLoaded so an optional Community Shaders thunk already
			// placed at PostPostLoad is preserved as our original call. Without
			// Community Shaders, the same hook continues through the vanilla path.
			InstallHooks();
			CDoF::UI::TryRegister();
		}
	}
}

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
	SetupLogging();
	spdlog::info("CinematicDoFStandalone loading");

	try {
		SKSE::Init(a_skse, false);
		SKSE::AllocTrampoline(28);
		const auto settings = CDoF::LoadSettings();
		CDoF::DoFRenderer::GetSingleton().SetSettings(settings);
		CDoF::UI::Initialize(settings);
		if (!SKSE::GetMessagingInterface()->RegisterListener(MessageHandler)) {
			spdlog::critical("Failed to register SKSE message listener");
			return false;
		}
		spdlog::info("Runtime {} accepted; waiting for post-load", REL::Module::get().version().string());
		return true;
	} catch (const std::exception& error) {
		spdlog::critical("Plugin load failed: {}", error.what());
		return false;
	} catch (...) {
		spdlog::critical("Plugin load failed with an unknown exception");
		return false;
	}
}
