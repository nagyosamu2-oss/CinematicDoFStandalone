# Transparency Actor Proximity Diagnostic Test20

## 日本語

これは透過対応の完成版ではなく、診断専用ビルドです。

Test19では、`flags=0x45` 前後のRGB変化方向だけでは装備と背景を区別できないことが分かりました。Test20は同じRGB差分に、投影したプレイヤーの頭―足元と身長由来の横幅から作る「狭い領域」を組み合わせます。

画面上のカメラ角度でカプセルが斜めにならないよう、広い領域と狭い領域はどちらも直立させています。狭い領域は頭―足元の範囲を少しだけ延長し、横幅を実測プレイヤー半径の1.65倍にします。これは装備スロットやマテリアルを読んだ結果ではなく、単なる位置的な事前条件です。

色の意味：

- **緑**：測定できるRGB変化があり、狭いプレイヤー領域の内側
- **シアン**：測定できるRGB変化があるが、狭い領域の外側（広い診断領域内）
- **マゼンタ**：RGB変化なし、狭いプレイヤー領域の内側
- **青**：RGB変化なし、狭い領域の外側（広い診断領域内）

白いベール、髪、ドレス本体、裾・トレーン、背景の植物や家具を比較してください。特に、装備が緑にまとまり、背景の変化部分がシアンへ分かれるかを確認します。シアンになった装備は「透過物ではない」という意味ではなく、今回の狭い位置条件から外れたことを表します。

通常のDoF合成は変更していません。この色表示は診断結果だけです。

## English

This is a diagnostic build, not the finished transparency fix.

Test19 showed that the direction of the RGB transition around `flags=0x45` does not by itself distinguish worn equipment from the background. Test20 combines the same RGB delta with a tight spatial region derived from the projected player head-to-feet span and the width estimated from that span.

Both the broad and tight regions remain upright on screen so orbit-camera perspective does not rotate the capsule. The tight region extends only slightly beyond the head-to-feet span and uses 1.65 times the measured player radius. It is only a spatial prior; it does not read equipment slots or material identity.

Colour key:

- **Green**: measurable RGB change inside the tight player region
- **Cyan**: measurable RGB change outside the tight region but inside the broad diagnostic region
- **Magenta**: no measurable RGB change inside the tight player region
- **Blue**: no measurable RGB change outside the tight region but inside the broad diagnostic region

Please compare the white veil, hair, main dress, hem/train, and background foliage or furniture. The key question is whether worn equipment groups into green while changed background areas separate into cyan. Equipment shown in cyan does not mean “not transparent”; it only means that the pixel fell outside this test's tight spatial prior.

Normal DoF composition is unchanged. These colours are diagnostic output only.
