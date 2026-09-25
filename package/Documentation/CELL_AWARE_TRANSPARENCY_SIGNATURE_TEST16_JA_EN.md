# Cell-Aware Transparency Signature Diagnostic Test 16

## 日本語

Test15では、屋外の `flags=0x45` がベールだけでなく空・地形を含む大きな描画領域まで更新していることが確認できました。差分強度もベールと背景の両方で非常に強く、閾値だけでは分離できません。

Test16は既存のフックを増やさず、セル種別ごとに取得する呼び出しだけを切り替えます。

- 屋内: Test13～15で反応を確認済みの `flags=0x45`
- 屋外: Test12のログにだけ現れた別経路 `flags=0x0C`（同一フレーム内の最初の該当呼び出し）

表示色はTest15と同じです。

- 水色: 弱い差分（0.00025以上）
- 黄色: 中程度の差分（0.002以上）
- マゼンタ: 強い差分（0.02以上）
- 白: 非常に強い差分（0.10以上）
- 通常色: 0.00025未満、またはプレイヤーカプセル外

屋外で次の2枚を撮影してください。

1. 透過ベール装備
2. 非透過装備

可能なら屋内の透過ベールも1枚撮影してください。屋外の巨大な半円・板状の背景反応が消え、ベールだけに色が出れば `0x0C` が透過保護の屋外入力候補です。ベールにも色が出なければ、この経路は候補から除外できます。

通常のDoF設定やTest20の白膜・空・月修正は変更していません。この版は診断専用で、Test15およびTest20とは別ブランチです。

## English

Test15 confirmed that exterior `flags=0x45` updates a large scene region containing sky and terrain, not just the veil. Both veil and background also reached very strong delta bands, so magnitude alone cannot separate them.

Test16 keeps the existing hook and changes only which call is captured for each cell type:

- Interior: the proven `flags=0x45` path used by Tests 13-15
- Exterior: the distinct `flags=0x0C` path found in the Test12 log (the first matching call in each frame)

The Test15 colour bands are retained:

- Cyan: weak delta (at least 0.00025)
- Yellow: medium delta (at least 0.002)
- Magenta: strong delta (at least 0.02)
- White: very strong delta (at least 0.10)
- Normal colour: below 0.00025 or outside the player capsule

Capture two exterior screenshots:

1. The transparent veil outfit
2. An opaque outfit

If practical, also capture one interior screenshot with the transparent veil. If the huge exterior dome/panel response disappears while the veil remains coloured, `0x0C` is a viable exterior input for transparency protection. If the veil has no response either, this path can be ruled out.

Normal DoF settings and the separate Test20 white-film/sky/moon fix are unchanged. This diagnostic build remains separate from Test15 and Test20.
