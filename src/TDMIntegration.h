#pragma once

namespace CDoF::TDMIntegration
{
	void Initialize();
	[[nodiscard]] bool IsAvailable();
	[[nodiscard]] RE::NiPointer<RE::TESObjectREFR> GetLockedTarget();
}
