# Transparency RGB Direction Diagnostic Test19

## 日本語

これは透過対応の完成版ではなく、診断専用ビルドです。

Test18により、屋内・屋外とも `flags=0x45` 前後のアルファチャンネルには有効な差分がないことが確認できました。Test19は同じ `flags=0x45` の前後を取得し、プレイヤー周辺のRGB変化を符号付きで分類します。

診断カプセルは、接写・低いカメラ角度で頭―足元の投影軸が斜めになる影響を避けるため、画面上で常に縦向きです。投影された長さと中心は維持します。

色の意味：

- **シアン**：パス後に輝度が上がった画素
- **マゼンタ**：パス後に輝度が下がった画素
- **黄色**：RGBは変化したが、輝度変化が小さい色変化／混合変化
- **青**：測定できるRGB差分なし

屋内と屋外で、白いベール、髪、ドレス、背景の植物がどの色になるかを比較してください。通常のDoF合成は変更しておらず、この色表示は診断結果だけです。

## English

This is a diagnostic build, not the finished transparency fix.

Test18 established that the alpha channel contains no useful change around the `flags=0x45` call, indoors or outdoors. Test19 captures the same call and classifies the signed RGB transition around the player.

The diagnostic capsule is now always upright in screen space. It keeps the projected centre and length while removing the large horizontal component that the projected head-to-feet axis acquires in close, low-angle orbit-camera views.

Colour key:

- **Cyan**: luminance increased after the pass
- **Magenta**: luminance decreased after the pass
- **Yellow**: RGB changed, but the luminance change is small (chromatic or mixed transition)
- **Blue**: no measurable RGB change

Please compare the white veil, hair, dress, and background vegetation indoors and outdoors. Normal DoF composition is unchanged; these colours are diagnostic output only.
