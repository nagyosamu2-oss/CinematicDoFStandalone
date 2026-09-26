# Transparency Empty Near-Gather Test25

## 日本語

これは、HDR64無効時の屋外で人物・髪・ベールの周囲に現れた黒い太い膜を確認する診断ビルドです。

既存のCoC互換判定は、人物境界へ背景色が回り込む旧来の膜を抑えます。ただし、拡張された近景ぼけ領域で全ての色サンプルが除外されると、空の色合計が黒として扱われる一方、合成用の被覆率だけが残り、黒い半透明膜になる経路がありました。

Test25は、近景色サンプルの有効重量が0の場合に近景レイヤーを空として出力します。それ以外の近景ぼけ、CoC互換判定、月・空の保護、Test24のメイン深度比較、HDR0専用補助は変更しません。

確認手順：

1. Community Shadersなし、`bUse64bitsHDRRenderTarget=0`で、黒膜が見えた屋外構図を再確認します。
2. 髪、ベール、腕、ドレスの外周から黒膜が消えるか確認します。
3. 同じ条件の屋内でも、近景ぼけや明るいボケが欠けないか確認します。
4. 可能ならHDR64有効時も短く確認し、Test24で改善した透過衣装が維持されているか確認します。

期待結果は、旧来の背景色の回り込みを再発させず、HDR0の黒膜だけが消えることです。

## English

This diagnostic build targets the thick black membrane seen around the actor, hair, and veil outdoors with 64-bit HDR disabled.

The existing CoC compatibility test prevents background colour from bleeding into foreground boundaries. However, it can reject every colour tap inside a dilated near-blur footprint. The empty colour sum then becomes black while independently calculated coverage remains non-zero, producing a dark translucent membrane.

Test25 outputs an empty near layer whenever its valid colour weight is zero. It does not otherwise change near blur, CoC compatibility, sky/moon protection, Test24's main-depth comparison, or the HDR-off assistance.

Retest the failing outdoor view without Community Shaders and with `bUse64bitsHDRRenderTarget=0`. Also check an interior and, if practical, the successful HDR64 configuration. The expected result is removal of the black membrane without restoring the older background-colour bleed.
