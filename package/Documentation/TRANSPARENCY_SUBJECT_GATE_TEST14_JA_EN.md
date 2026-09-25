# Transparency Subject Gate Diagnostic Test 14

## 日本語

Test13で確定した `flags=0x45` の透過差分を、プレイヤーの投影範囲から広げたカプセル内だけに絞ります。通常のDoF設定やTest20の白膜・空・月修正は変更しません。

同じベールで屋内と屋外を確認してください。水色は「透過差分かつプレイヤー近傍として採用された部分」です。

- ベール本体、左右へ広がる部分、裾・後方の長い部分が水色で残るか
- プレイヤーから離れた木、草、室内の透明物が通常色へ戻るか
- カメラを近づけた場合と全身が映る距離の両方で、不自然な直線状の切れ目が出ないか

屋内・屋外を各1枚、可能なら屋外は全身とベールの裾が見える構図が比較しやすいです。

この版は診断専用で、Test13およびTest20とは別ブランチです。

## English

Test14 restricts the `flags=0x45` transparency delta confirmed by Test13 to an expanded capsule projected around the player. It does not change normal DoF settings or the separate Test20 sky/foliage/moon fix.

With the same veil, test indoors and outdoors. Cyan means a transparency change accepted as being near the player.

- Check that the veil body, its wide sides, and its long trailing sections remain cyan.
- Check that distant trees, grass, and unrelated indoor transparent objects return to their normal colour.
- At both close and full-body camera distances, look for an unnatural straight cutoff.

One interior and one exterior screenshot are sufficient; an exterior full-body view showing the veil train is especially useful.

This is a diagnostic build kept separate from Test13 and Test20.
