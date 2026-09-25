# Transparency Color Delta Diagnostic Test5

## 日本語

### 目的

ヴェールや髪などの半透明素材を、背景の深度だけに頼らず識別できるか確認する診断版です。

Test3 / Test4 の周辺深度伝播は素材そのものを判別できず、固定ピントと低いF値の組み合わせで遠景まで反応しました。Test5はその方式を使用しません。

Skyrimの透過描画パスの直前と直後のシーンカラーを取得し、その描画によって実際に色が変化した画素をマゼンタで表示します。DoFのピント距離、F値、対象追従には依存しません。

### 確認してほしい点

1. ヴェールの布面・レース模様がマゼンタになるか
2. 髪、草、木の葉、粒子など、ほかにマゼンタになる素材
3. 通常の地形・建物・空まで広範囲にマゼンタにならないか
4. カメラ移動時のちらつき、クラッシュ、描画崩れの有無
5. FPS（診断版はフル解像度の画面を2枚追加保持・コピーするため、一時的に重くなる可能性があります）

ヴェールがマゼンタになれば、次の版でこの信号を限定的なDoF保護へ変換します。画面全体または不透明背景まで反応する場合は、捕捉区間をさらに狭める必要があります。

### 注意

- 診断専用です。マゼンタ表示は仕様です。
- Cinematic DoF Standalone 1.0.2 を上書きしてください。
- 問題が起きた場合はTest2へ戻してください。
- ビルド確認済みですが、ゲーム内動作は未検証です。

## English

### Purpose

This diagnostic build tests whether translucent materials such as veils and hair can be identified without relying only on the background depth value.

The neighbour-depth propagation used by Test3 / Test4 could not identify materials and also reacted to distant scenery with fixed focus and a low f-number. Test5 does not use that method.

It captures the scene colour immediately before and after Skyrim's transparency rendering pass and displays pixels actually changed by that pass in magenta. The result is independent of focus distance, f-number, and target tracking.

### What to check

1. Whether the veil surface and lace pattern become magenta
2. Which other materials become magenta, including hair, grass, foliage, and particles
3. Whether ordinary terrain, buildings, or the sky become magenta over large areas
4. Flickering, crashes, or rendering corruption while moving the camera
5. FPS (this diagnostic temporarily keeps and copies two additional full-resolution images, so it may be heavier)

If the veil becomes magenta, the next build can convert this signal into narrowly scoped DoF protection. If most of the screen or opaque scenery reacts, the captured rendering interval must be narrowed further.

### Notes

- This is a diagnostic build. The magenta display is intentional.
- Install it over Cinematic DoF Standalone 1.0.2.
- Return to Test2 if any problem occurs.
- The project and shader compile successfully, but in-game behaviour has not yet been verified.
