# Transparency Main Depth Comparison Test24

## 日本語

これは透過衣装の欠落原因を深度バッファ経路で切り分ける診断ビルドです。

Test23のログでは、プレイヤー3Dツリーから有効なGeometry境界を1件も取得できませんでした。一方、ReShadeのGeneric Depth画面では、屋内・屋外ともフル解像度の `2560x1440 D24S8` が自動選択されています。

Test24では、Community Shadersが読み込まれ、SkyrimのSAOが無効な場合でも、従来の `POST_ZPREPASS_COPY` フォールバックを使わず、通常のメイン深度を強制使用します。Community ShadersやReShadeは、このビルドの動作に必須ではありません。

今回は診断色を表示しません。通常のDoF画面で、問題の衣装・髪・ベール・裾・トレーンが以前より正しく扱われるかを確認してください。

確認手順：

1. Test24を導入し、ゲームを完全に再起動します。
2. 同じ衣装で、屋内と屋外をそれぞれ確認します。
3. DoFを有効にした通常画面のスクリーンショットを撮ります。
4. 可能なら同じゲーム起動中にReShadeの「アドオン」→「Generic Depth」を開き、選択中の最上段を撮影します。
5. 最新の `Documents\My Games\Skyrim Special Edition\SKSE\CinematicDoFStandalone.log` も共有してください。

ログには `Test24 main depth` と `Test24 post-z-prepass-copy depth` が出力されます。同じ起動中のReShade画面と比較するため、ゲームを再起動する前に両方を記録してください。

判定：

- 衣装の欠落が改善する：深度フォールバック経路が主因です。メイン深度を正式採用する条件を整理します。
- 変化しない：問題は深度バッファの選択だけではなく、透過物の描画順または色バッファ側にあります。
- 別の遮蔽・輪郭問題が出る：メイン深度には必要な衣装が入る一方、現在のフォールバックが避けていた副作用があります。

## English

This diagnostic build isolates the depth-buffer path as the cause of the missing transparent outfit.

Test23 logged zero usable geometry bounds from the player's 3D tree. Meanwhile, ReShade Generic Depth consistently selected the full-resolution `2560x1440 D24S8` resource indoors and outdoors.

Test24 forces the normal main depth instead of the `POST_ZPREPASS_COPY` fallback, even when Community Shaders is loaded and Skyrim SAO is disabled. Neither Community Shaders nor ReShade is required for this build to function.

There are no diagnostic colours in Test24. Judge the normal DoF result, especially the outfit, hair, veil, hem, and train.

Test indoors and outdoors with the same outfit. If possible, capture ReShade Add-ons → Generic Depth and the latest `CinematicDoFStandalone.log` during the same game run. The log prints `Test24 main depth` and `Test24 post-z-prepass-copy depth` so their resource details can be compared.

- Improvement means the fallback depth path is the primary cause.
- No change means depth selection alone is insufficient, and the next target is transparent draw order or the colour buffer.
- New occlusion or edge artifacts mean main depth contains the outfit but also reintroduces a side effect previously avoided by the fallback.
