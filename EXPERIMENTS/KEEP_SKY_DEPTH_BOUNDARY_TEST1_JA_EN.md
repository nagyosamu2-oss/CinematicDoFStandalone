# Keep Sky Sharp: Depth-Boundary Composition Test 1

## 日本語

### 目的

`空を鮮明に保つ`を有効にし、F値を下げて遠景ぼけを強くしたときに、月・山・木・建物の周囲へ広がる発光状の境界を確認するテストです。

### Test 1 の変更

- 空の保護判定を、ぼけ半径に応じて内側へ縮める多重リング方式から、フル解像度深度の正確なピクセル判定へ変更しました。
- 遠景ぼけの採取時に、深度上で空または月と判定された色を地形側へ運ばないようにしました。
- `空を鮮明に保つ`が無効な場合の処理、近景ぼけ、透過対応、HDR0用アルファ形式修正には変更を加えていません。

### 確認項目

1. `空を鮮明に保つ`を有効にします。
2. F値を下げ、以前の円形または発光状の境界が出やすい設定にします。
3. 月、山の稜線、木の枝葉、建物と空の境界を確認します。
4. 空が鮮明なまま、境界の拡張や発光が減るか確認します。
5. 境界が硬い切り抜き、ギザギザ、暗い縁へ変化していないかも確認します。
6. 比較として`空を鮮明に保つ`を無効にし、通常のDoFが従来どおりか確認します。

この版は挑戦枠の診断テストであり、ゲーム内確認が完了するまでは正式統合版ではありません。

## English

### Purpose

This test targets the expanding or glowing boundary around the moon, mountains, trees, and buildings when Keep Sky Sharp is enabled with a wide aperture.

### Test 1 changes

- Replaces the blur-radius-dependent multi-ring sky inset with the exact full-resolution depth classification.
- Prevents far-blur geometry gathers from transporting color classified as clear sky or far-depth moon across the depth boundary.
- Does not change the Keep Sky Sharp-off path, near blur, transparency handling, or the HDR0 alpha-capable near-blur format fix.

### Checks

1. Enable Keep Sky Sharp.
2. Lower the F-number to reproduce the previous circular or glowing boundary.
3. Inspect the moon, mountain ridges, tree foliage, and buildings against the sky.
4. Confirm that the sky remains sharp while the expanding/glowing boundary is reduced.
5. Check for new hard cut-outs, jagged edges, or dark outlines.
6. Disable Keep Sky Sharp once and confirm that ordinary DoF remains unchanged.

This is an experimental diagnostic build and is not a final integrated release until it has been verified in game.
