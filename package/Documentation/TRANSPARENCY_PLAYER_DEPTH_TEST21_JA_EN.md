# Transparency Player Depth Diagnostic Test21

## 日本語

これは透過対応の完成版ではなく、診断専用ビルドです。

Test20では、狭いプレイヤー領域によって人物中央を位置的に絞れる一方、中央に重なった背景も同じ領域へ入り、裾やトレーンは領域外へ出ることが分かりました。Test21は装備スロットなどのゲーム固有条件へ進む前に、`flags=0x45` 前後でRGBが変化した画素の深度を、投影したプレイヤーの深度と比較します。

色の意味：

- **緑**：RGB変化あり、プレイヤー深度に近く、狭いプレイヤー領域の内側
- **黄色**：RGB変化あり、プレイヤー深度に近いが、狭い領域の外側
- **シアン**：RGB変化あり、深度バッファ上ではプレイヤーより後方
- **マゼンタ**：RGB変化あり、深度バッファ上ではプレイヤーより前方
- **青**：測定できるRGB変化なし

白いベール、髪、ドレス本体、裾・トレーンと、それらの背後の家具・植物・空・地形を比較してください。特に、人物中央が緑、裾やトレーンが黄色、背景がシアンへ分かれるかを確認します。

透明な装備がシアンになる場合も重要な結果です。透明面が深度を書かず、背後の深度が見えている可能性を示すためです。したがってシアンは「装備ではない」という確定判定ではありません。

通常のDoF合成は変更していません。この色表示は診断結果だけです。

## English

This is a diagnostic build, not the finished transparency fix.

Test20 showed that a tight player region can spatially isolate the middle of the character, but background overlapping that region is included while the hem and train can fall outside it. Before moving to game-specific conditions such as equipment slots, Test21 compares the main depth-buffer value of pixels changed around `flags=0x45` with the projected player depth.

Colour key:

- **Green**: RGB changed, depth is close to the player, and the pixel is inside the tight player region
- **Yellow**: RGB changed and depth is close to the player, but the pixel is outside the tight region
- **Cyan**: RGB changed and the depth buffer places the pixel behind the player
- **Magenta**: RGB changed and the depth buffer places the pixel in front of the player
- **Blue**: no measurable RGB change

Please compare the white veil, hair, main dress, hem/train, and the furniture, foliage, sky, or terrain behind them. The useful result would be a green character centre, a yellow hem/train, and a cyan background.

A transparent equipment pixel becoming cyan is also important evidence. It may mean that the transparent surface does not write depth and the buffer still contains the depth of the background behind it. Cyan therefore does not conclusively mean “not equipment.”

Normal DoF composition is unchanged. These colours are diagnostic output only.
