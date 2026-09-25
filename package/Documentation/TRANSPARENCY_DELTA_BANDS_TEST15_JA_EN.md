# Transparency Delta Bands Diagnostic Test 15

## 日本語

Test14の非透過装備比較で、プレイヤーカプセル内の背景にも弱い透過差分が存在すると分かりました。Test15は同じカプセル内の差分強度を色分けし、ベールと背景ノイズを分離できる閾値を測る診断版です。通常のDoF設定やTest20の白膜・空・月修正は変更しません。

- 水色: 弱い差分（0.00025以上）
- 黄色: 中程度の差分（0.002以上）
- マゼンタ: 強い差分（0.02以上）
- 白: 非常に強い差分（0.10以上）
- 通常色: 0.00025未満、またはプレイヤーカプセル外

同じ場所とカメラ距離で、次の2種類を各1枚ずつ撮影してください。

1. 透過ベール装備
2. 非透過装備

ベール本体・裾と、装備背後の空いた背景が異なる色帯になれば、その間を最終的な透過保護閾値にできます。屋外の全身構図が最も比較しやすく、屋内は任意です。

この版は診断専用で、Test14およびTest20とは別ブランチです。

## English

The opaque-outfit control in Test14 showed a weak transparency delta across the background inside the player capsule. Test15 colour-codes the delta magnitude in that same capsule so the veil signal can be separated from the background floor without guessing a production threshold. Normal DoF settings and the separate Test20 sky/foliage/moon fix are unchanged.

- Cyan: weak delta (at least 0.00025)
- Yellow: medium delta (at least 0.002)
- Magenta: strong delta (at least 0.02)
- White: very strong delta (at least 0.10)
- Normal colour: below 0.00025 or outside the player capsule

At the same location and camera distance, capture one screenshot for each:

1. The transparent veil outfit
2. An opaque outfit

If the veil body/train and the empty background behind the opaque outfit land in different colour bands, the boundary between them can become the final transparency-protection threshold. An exterior full-body view is the most useful; an interior comparison is optional.

This is a diagnostic build kept separate from Test14 and Test20.
