# Transparency Capture-Region Remap Diagnostic Test9

## 日本語

Test8の動画と比較画像により、分裂は光そのものではなく、透過スナップショットを採取する内部解像度と、診断色を合成する表示解像度の不一致である可能性が高くなりました。Community Shadersのアップスケール倍率を下げるほど、同じ輪郭のずれが大きくなることが決め手です。

Test9はTest8の分類条件と色を変えません。変更するのは透過スナップショットの参照座標だけです。

- 透過/effects描画の直前に、その時点の有効ビューポートを保存します。
- 直後のビューポートが一致したフレームだけを有効にします。
- アップスケール後の画素座標を正規化し、保存した内部解像度ビューポートへ再マップして比較します。
- シアンは手前深度アンカー1点、マゼンタは整合する手前深度アンカー2点以上というTest8の意味を維持します。

### 確認してほしい点

1. FSR 3.1のNative AA、Quality、Balanced、Performance、Ultra Performanceで、同じ輪郭が扇状・階段状に分裂しなくなるか。
2. カメラを左右に振ったとき、水色のヴェールや人物輪郭が現在の物体位置に追従するか。
3. 窓、照明、植物などにも色は出ても、その色が実物の位置と大きさに一致するか。
4. Test8と同様、ピント方式やF値を変えても色の判定自体がほぼ変わらないか。

この版も診断表示だけで、CoC、深度、最終的なピントは変更しません。「手前ぼけに膜が張る」問題も別経路のため未変更です。

### 導入

Skyrimを終了してから、MO2でTest8より下に置くか、以前の診断版を無効化して本ZIPを有効化してください。

## English

The Test8 video and upscaling comparisons indicate that the split silhouettes are not caused by lighting itself. They are consistent with reading a transparency snapshot captured in the internal-resolution viewport as if it used the later display-resolution coordinates. The widening displacement at lower FSR 3.1 scales is the decisive clue.

Test9 keeps the Test8 classifier and colours unchanged. It records the active viewport around Skyrim's transparency/effects interval, validates that the before/after captures use the same viewport, and maps post-upscale output UVs back into that captured internal-resolution region before comparing the snapshots.

Please compare Native AA, Quality, Balanced, Performance, and Ultra Performance while panning the camera. The cyan/magenta shapes should remain attached to the current objects instead of producing fan- or stair-shaped copies. Windows, lights, vegetation, and other transparency/effect draws may still be coloured; the important test is whether their position and size are correct.

This remains a visualization-only diagnostic and does not modify CoC, depth, final focus, or the separate sheet-like near-blur behaviour.
