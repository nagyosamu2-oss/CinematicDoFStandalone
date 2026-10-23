# CinematicDoFStandalone 1.0.7 — Nexus changelog

## 日本語

- 絞り・星・ハートの形状ボケと「内部を滑らかに埋める」を追加しました。
- 4・5・6・8・10・12本の回折光条、強さ、長さ、回転を追加しました。
- 明部抽出しきい値、ボケ中心の補光、広域フレア抑制、強光源抑制を追加しました。
- Bottled Shadersの通常Z／Reverse Z Depth Bufferへ対応しました。
- プリセット7「絞り形状」と8「光条」を追加し、実ゲームで調整した初期値を反映しました。
- プリセット10「カスタム2」を、一定距離まで鮮明に見せる箱庭風の初期設定へ更新しました（名称は変更していません）。
- Custom 1／2を保存値と内部IDを保ったまま9／10番へ移動しました。
- UI内の共通設定と形状・光条固有設定を整理しました。
- 既存INIとの互換性を維持します。

## English

- Added aperture, star, and heart bokeh plus filled aperture sampling.
- Added diffraction starburst with 4, 5, 6, 8, 10, or 12 rays, strength, length, and rotation controls.
- Added Highlight Extraction Threshold, Bokeh Core Fill, Wide-Flare Suppression, and Strong-Light Suppression.
- Added support for conventional and reversed Z depth under Bottled Shaders.
- Added in-game-tuned preset 7 Aperture Bokeh and preset 8 Starburst.
- Updated preset 10 Custom 2 to a miniature-style setup that stays sharp through a set distance, without renaming the preset.
- Moved Custom 1/2 to slots 9/10 without changing saved values or stable internal IDs.
- Reorganized shared quality controls and shape/starburst-specific controls.
- Existing INIs remain compatible.
