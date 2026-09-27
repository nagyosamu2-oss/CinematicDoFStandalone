# HDR0 Near-Blur Alpha Format Test 1 / HDR0近景ぼけアルファ形式 Test 1

## 日本語

これは統合版1.0.2を基準にした最小診断版です。HDR0の`R11G11B10_FLOAT`にはアルファチャンネルがない一方、近景ぼけシェーダーは中間テクスチャのアルファへ被覆率を保存し、最終合成で読み戻します。

この版は入力色形式が`R11G11B10_FLOAT`のときだけ、半解像度の近景ぼけ中間テクスチャを`R16G16B16A16_FLOAT`で作成します。遠景ぼけ、最終出力、深度、CoC、HDR1経路、透過対応は変更しません。

### 確認項目

1. HDR0で、人物・髪・衣装・武器・草の外周にあった黒い点線が消えるか確認します。
2. 人物を画面中央と端へ移動し、カメラ距離と手前最大ぼかしを変えます。
3. HDR0で近景ぼけの濃さや境界が不自然に薄くならないことを確認します。
4. HDR1でも同じ構図を一度確認し、従来表示から変化していないことを確認します。
5. 透過衣装とベールが統合版と同じく正常であることを確認します。

ログの`Created depth-of-field resources`には、HDR0で`color format 26, near-blur format 10`と表示される想定です。`26`は`R11G11B10_FLOAT`、`10`は`R16G16B16A16_FLOAT`です。

## English

This is a minimal diagnostic build based on the integrated 1.0.2 candidate. HDR0 uses `R11G11B10_FLOAT`, which has no alpha channel, while the near-blur shader stores coverage in the intermediate texture alpha and reads it back during final compositing.

Only when the input colour format is `R11G11B10_FLOAT`, this build creates the half-resolution near-blur intermediate as `R16G16B16A16_FLOAT`. Far blur, final output, depth, CoC, the HDR1 path, and the validated transparency handling are unchanged.

### Checks

1. Under HDR0, check whether the black dotted outline disappears around actors, hair, clothing, weapons, and grass.
2. Move the actor between the centre and screen edge, and vary camera distance and maximum near blur.
3. Confirm that HDR0 near-blur strength and boundaries do not become unnaturally weak.
4. Repeat one composition under HDR1 and confirm that it remains unchanged.
5. Confirm that transparent clothing and the veil still match the integrated candidate.

The `Created depth-of-field resources` log line is expected to report `color format 26, near-blur format 10` under HDR0. `26` is `R11G11B10_FLOAT`; `10` is `R16G16B16A16_FLOAT`.
