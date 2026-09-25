# Foreground Depth Boundary Test 1

## 日本語

これは **Cinematic DoF Standalone 1.0.2 専用の実験版更新パッチ**です。

人物と背景の境界、および髪・レース・ヴェールなどの細い素材が背景ぼけへ溶け込む現象を軽減するため、CoC（ぼけ量）を作る段階に1ピクセル近傍の深度境界補正を追加しています。

- 公開版1.0.2を土台にしています。
- 既存の人物保護、空・月の保護、設定画面は変更していません。
- 背景側のピクセルだけを対象に、上下左右の1ピクセル以内に「より手前で、よりピントに近い」深度がある場合、その近傍のCoCを採用します。
- UIやINI設定はありません。効果を確認するための固定値テストです。
- 他のDoFシェーダーのソースコードは使用していません。一般的な深度近傍判定を独自に実装したものです。

### 確認してほしい点

1. 人物の輪郭、髪、レース、ヴェールと背景の境界が自然になったか
2. 輪郭に不自然な鋭い線や1ピクセルの縁取りが出ないか
3. カメラ移動中に境界がちらつかないか
4. 人物以外の前景と背景の境界に副作用がないか

最初はDLSS/FSRなどのアップスケーラーを無効にして比較し、その後いつもの構成でも確認してください。

## English

This is an **experimental update patch for Cinematic DoF Standalone 1.0.2 only**.

It adds a one-pixel depth-boundary refinement while the circle of confusion (CoC) is generated. The goal is to reduce background blur leaking into character silhouettes and thin materials such as hair, lace, and veils.

- It is based on the public 1.0.2 release.
- Existing subject protection, sky/moon protection, and the settings UI are unchanged.
- Only far/background pixels are considered. When an immediate cardinal neighbour is nearer and has a smaller CoC, the boundary pixel adopts that neighbour's CoC.
- There is no UI or INI option. This test intentionally uses fixed values.
- No source code from another DoF shader is used; this is an independent implementation of a general neighbouring-depth technique.

Please check character and transparency boundaries, sharp one-pixel outlines, shimmer during camera movement, and unintended changes on non-character depth edges. Compare first without DLSS/FSR, then with your normal setup.
