# Optional Test6 Transparency Test 1

## 日本語

このオーバーレイは、完成版の通常描画と Test6 の透過処理を完全に分離して切り替える個人向け検証版です。

- 「Test6透過処理を有効にする」が OFF の場合、完成済みの通常描画をそのまま使用します。
- ON の場合だけ、二重深度から透過候補を推定します。
- Test4 が透過候補の全面へ適用していた強い境界補正を、Test6 と同じく候補側の外周・急変部だけへ限定します。
- 広いベール内部では通常のぼかしを維持し、レースやベールの質感は既存の高周波・中周波復元で限定的に保持します。
- 非常に細い透過素材は、領域全体が境界として扱われる場合があります。

通常モードの透過物の鮮明さ、月の白膜対策、HDR0境界対策、人物境界、シルエット、画面ピント照準、ロックオンフォーカス、スニークモードには変更を加えていません。

更新用ZIPには既存設定を保護するためINIを含めていません。既存の `ExperimentalTransparency` 設定値はそのまま引き継がれます。

## English

This personal test overlay keeps the completed normal renderer fully separated from the optional Test6 transparency path.

- With “Enable Test6 Transparency Path” OFF, the completed normal renderer remains unchanged.
- Only ON enables the dual-depth transparency-candidate heuristic.
- Test6 limits the stronger boundary compensation, which Test4 applied across the entire candidate region, to the candidate-side outer edge and abrupt mask transitions.
- Broad veil interiors retain normal background blur while existing high- and medium-frequency recovery preserves a limited amount of lace and veil texture.
- Extremely thin transparent materials may be classified entirely as boundary.

The normal renderer's transparent-material sharpness, moon white-film protection, HDR0 boundary handling, subject boundaries, silhouette mode, screen focus reticle, lock-on focus, and sneak mode are unchanged.

The update ZIP intentionally contains no INI so existing settings are preserved. The existing `ExperimentalTransparency` value carries over unchanged.
