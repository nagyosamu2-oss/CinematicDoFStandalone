# Keep Sky Sharp: Boundary Coverage Test 3 / 空を鮮明に保つ：境界被覆率テスト3

## 日本語

これはTest2を土台にした累積診断版です。透過対応、HDR0黒点線枠修正、深度境界Test1、mip 0固定Test2を含みます。

Test1では明るい空が木・山・建造物へ運ばれることを防ぎ、空と月を元画像から復元しました。その副作用として、葉や細い枝のように「物体と空が1ピクセル単位で交互になる境界」は、空側だけが完全復元され、空を背景にした部分だけ輪郭が鮮明に見える場合があります。

Test3では、空ピクセルの周囲3x3にある実ジオメトリの割合を被覆率として推定します。空だけに囲まれた内部は従来どおり完全に鮮明なまま保ち、木・山・建造物に接する1ピクセルの空境界だけ、被覆率に応じてフィルター済み遠景ぼけを戻します。以前問題になった「ぼけ半径ぶん拡張する保護帯」は復活させません。

確認項目：

- 空を背景にした木・枝・葉だけが不自然に鮮明になる差が減るか
- 山や建造物を背景にした部分とのぼけ方が揃うか
- 月と空の鮮明さが維持されるか
- 山・建造物の白化／発光状拡張が再発しないか
- 細い輪郭に暗線、白線、ちらつきが出ないか

## English

This cumulative diagnostic build is based on Test 2 and includes the transparency work, HDR0 dotted-outline fix, Depth Boundary Test 1, and the mip-zero Test 2.

Test 3 estimates local geometry coverage from a 3x3 raw-depth neighborhood. Interior sky remains restored exactly, while only the one-pixel clear-depth boundary beside foliage, mountains, or buildings receives a fractional amount of the filtered far layer. This is intended to soften thin silhouettes against the sky without restoring the earlier blur-radius-sized unprotected halo.

Please compare foliage against sky and against terrain, while checking that the moon and interior sky stay sharp and that mountain/building glow, bright fringes, dark fringes, or temporal shimmer do not return.
