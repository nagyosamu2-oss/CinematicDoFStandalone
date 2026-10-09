# Hair Blending Modes Test 3

## 日本語

完成済みの通常描画を保ったまま、髪やベール越しの背景ぼかしを選べる検証用オーバーレイです。

- 「空を鮮明に保つ」と「髪を馴染ませる」を、会話外DoF・言語選択の一段下へ配置しました。
- 「髪を馴染ませる」をOFFにすると、完成済みの通常シェーダーだけを使用します。
- ONでは右側の「1」「2」で方式を選択します。
- モード1は元のTransparencyEdgeOnlyBoundary-Test6です。
- モード2は元のSkyFoliage-HybridTransparency-Test8です。
- Test 3では、統合時に欠けていた最終復元パスの焦点・二重深度入力を元のTest6/Test8 DLLと同じ構成へ戻しました。
- 通常版、Test6、Test8は別々のシェーダー集合として読み込み、1フレームでは選択中の1集合だけを実行します。
- 追加の中間テクスチャや追加描画はありません。増えるのは起動時のシェーダー準備時間、シェーダーオブジェクト用メモリ、パッケージ容量だけです。
- Test6またはTest8の準備に失敗した場合、その方式は通常描画へ自動的にフォールバックします。
- ポップアップ説明は、主な見た目の効果である「髪の後ろをぼかして背景になじませる」ことと、ベールなどの透過素材が少しぼやける点を案内します。

更新用ZIPには既存設定を保護するためINIを含めていません。

## English

This test overlay keeps the completed stable renderer intact while offering optional background blur behind hair and veils.

- “Keep Sky Sharp” and “Blend Hair” now appear on a prominent row directly below the outside-dialogue and language controls.
- With “Blend Hair” OFF, only the completed stable shader set is used.
- When enabled, buttons “1” and “2” select the treatment.
- Mode 1 is the original TransparencyEdgeOnlyBoundary-Test6 shader.
- Mode 2 is the original SkyFoliage-HybridTransparency-Test8 shader.
- Test 3 restores the focus and dual-depth inputs used by the original Test6/Test8 DLL in the final detail-recovery pass; those bindings were missing from the earlier combined build.
- Stable, Test6, and Test8 are loaded as separate shader sets; only the selected set executes in a frame.
- No extra intermediate textures or extra rendering passes are added. The trade-off is limited to startup shader preparation time, shader-object memory, and package size.
- If either optional set cannot be prepared, that unavailable mode automatically falls back to stable rendering.
- The tooltip describes the main visual benefit—softening the scenery behind hair so the edge blends naturally—and notes that transparent materials such as veils may become slightly softer.

The update ZIP intentionally contains no INI so existing settings are preserved.
