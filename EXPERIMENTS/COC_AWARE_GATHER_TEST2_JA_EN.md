# CoC-aware Gather Test 2

## 日本語

これは **Cinematic DoF Standalone 1.0.2 専用の実験版更新パッチ**です。

Test1の1ピクセル深度境界補正を維持したまま、ぼかし色を集める処理にCoC（ぼけ量）の適合判定を追加しています。

- 遠景ぼけでは、中心とぼけ量が大きく異なるサンプルを滑らかに弱めます。
- 近景ぼけでは、背景側の正CoCを持つ色を近景レイヤーへ取り込まないようにします。
- 既存の人物保護、空・月の保護、設定画面は変更していません。
- UIやINI設定はありません。効果を比較するための固定値テストです。
- 他のDoFシェーダーのソースコードは使用していません。一般的なCoC差判定を独自に実装しています。

### 確認してほしい点

1. 人物・髪・レース・ヴェールの境界へ背景色が回り込む量が減ったか
2. Test1より輪郭が硬くなりすぎていないか
3. 背景の連続した奥行きに縞や段差が出ないか
4. 明るいボケや近景ボケが欠けたり暗くなったりしないか
5. カメラ移動時に境界がちらつかないか

透過素材を直接識別する処理ではないため、ヴェール全体を人物深度として扱うものではありません。今回は背景色が境界へ混ざる経路を抑える段階です。

## English

This is an **experimental update patch for Cinematic DoF Standalone 1.0.2 only**.

It retains Test1's one-pixel depth-boundary refinement and adds CoC compatibility checks while gathering blur colour.

- Far blur smoothly suppresses samples whose CoC differs substantially from the centre.
- Near blur avoids gathering positive-CoC background colour into the dilated foreground layer.
- Existing subject protection, sky/moon protection, and the settings UI are unchanged.
- There is no UI or INI option. This test intentionally uses fixed values.
- No source code from another DoF shader is used; the CoC-difference checks are independently implemented.

Please compare boundary colour bleed, excessive edge hardness, depth banding, missing or darkened bokeh, and shimmer during camera movement. This does not directly identify transparent materials or assign the entire veil to subject depth; it is specifically testing rejection of incompatible blur samples.
