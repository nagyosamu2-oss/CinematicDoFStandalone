# Second Exterior Transparency Call Diagnostic Test 17

## 日本語

Test16の実ゲーム検証では、屋内 `flags=0x45` の色帯は正常に表示されましたが、屋外で最初に現れる `flags=0x0C` にはベールも背景も色帯が出ませんでした。これにより、起動・シェーダー更新・屋内経路は正常で、屋外 `0x0C` の1回目には測定可能な色差分がないと確認できました。

Test12のログでは屋外 `flags=0x0C` が1フレームに2回呼ばれています。Test17は既存フックをそのまま使い、次の呼び出しだけを取得します。

- 屋内: `flags=0x45`
- 屋外: 同一フレーム内で2回目の `flags=0x0C`

表示色はTest15～16と同じです。

- 水色: 弱い差分（0.00025以上）
- 黄色: 中程度の差分（0.002以上）
- マゼンタ: 強い差分（0.02以上）
- 白: 非常に強い差分（0.10以上）
- 通常色: 0.00025未満、またはプレイヤーカプセル外

まず屋外の透過ベールを1枚撮影してください。色帯が出た場合のみ、同じ構図で非透過装備も1枚お願いします。屋外が再び完全な通常表示なら、`0x0C`は両方とも透過保護の入力候補から除外できます。

通常のDoF設定やTest20の白膜・空・月修正は変更していません。この版は診断専用です。

## English

In-game Test16 validation showed the expected interior colour bands from `flags=0x45`, but the first exterior `flags=0x0C` call produced no bands on either the veil or background. This confirms that loading, shader deployment, and the interior path are working, while the first exterior `0x0C` call contains no measurable colour delta.

The Test12 log showed two exterior `flags=0x0C` calls per frame. Test17 keeps the existing hook and captures only:

- Interior: `flags=0x45`
- Exterior: the second `flags=0x0C` call in the frame

The Test15-16 colour bands are unchanged.

- Cyan: weak delta (at least 0.00025)
- Yellow: medium delta (at least 0.002)
- Magenta: strong delta (at least 0.02)
- White: very strong delta (at least 0.10)
- Normal colour: below 0.00025 or outside the player capsule

First capture one exterior screenshot with the transparent veil. Only if colour bands appear, please capture the same view with an opaque outfit. If the exterior remains completely normal again, both `0x0C` calls can be ruled out as transparency-protection inputs.

Normal DoF settings and the separate Test20 white-film/sky/moon fix are unchanged. This build is diagnostic only.
