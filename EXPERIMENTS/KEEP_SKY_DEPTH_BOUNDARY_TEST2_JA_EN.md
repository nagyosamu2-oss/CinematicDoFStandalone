# Keep Sky Sharp: Depth Boundary Test 2 / 空を鮮明に保つ：深度境界テスト2

## 日本語

これは診断用の累積テスト版です。透過対応、HDR0の黒い点線枠修正、および深度境界テスト1を含みます。

`空を鮮明に保つ`が有効な場合だけ、遠景ぼけの色取得を最も細かい階層（mip 0、半解像度）に固定します。粗い色階層を作る段階ですでに明るい空が山や建造物へ混ざっているかを切り分けるための変更です。無効時の遠景ぼけ、近景ぼけ、HDR0修正、透過処理は変更しません。

確認項目：

- `空を鮮明に保つ`を有効にし、同じ構図で F/9 前後と F/1.0 を比較する
- F/1.0で山・建造物の白化や発光状の拡張が軽減するか
- 月と木の改善が維持されるか
- 強いぼけで粒状感、輪郭のざらつき、FPS低下が目立たないか
- `空を鮮明に保つ`を無効にした表示が従来どおりか

これは最終方式ではありません。効果が確認できた場合は、常時mip 0固定ではなく、空と地形を混ぜない深度対応の色ピラミッドへ置き換える候補になります。

## English

This is a cumulative diagnostic build. It includes the transparency work, the HDR0 dotted-outline fix, and Depth Boundary Test 1.

Only while `Keep Sky Sharp` is enabled, far-blur color gathering is forced to the finest level (mip 0, half resolution). This isolates whether bright sky has already leaked into mountains and buildings while the coarse color pyramid is generated. Far blur with the option disabled, near blur, the HDR0 fix, and transparency handling are unchanged.

Please compare the same view around F/9 and F/1.0, checking distant mountain/building whitening, the retained moon/tree improvement, sampling grain or outline noise, performance, and the unchanged option-off path.

This is diagnostic rather than a final solution. A successful result would support replacing the forced mip with a depth-aware color pyramid that does not mix sky and geometry.
