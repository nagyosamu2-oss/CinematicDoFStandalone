# Transparency Alpha Signal Diagnostic Test18

## 日本語

### 目的

Test16とTest17により、屋外で2回呼ばれる `flags=0x0C` はどちらも画面差分を持たないことが確認できました。屋外で反応するのは1回だけの `flags=0x45` ですが、RGB差分にはベールだけでなく広い背景更新も混在します。

Test18は屋内・屋外とも `flags=0x45` の前後を取得し、プレイヤー周辺でRGB差分とアルファ差分を同時に分類します。

- **緑**: RGB差分のみ
- **赤**: アルファ差分のみ
- **黄**: RGB差分とアルファ差分の両方
- **青**: どちらの差分もなし

### 確認してほしい点

1. 屋内で、ベール・髪・衣装・背景がそれぞれ何色になるか
2. 屋外で、ベール・髪・衣装・背景がそれぞれ何色になるか
3. 特にベールに赤または黄が出て、背景が緑または青になるか

屋内・屋外を各1枚、可能なら同じ装備・近い構図で撮影してください。アルファ差分がベールだけに現れれば、次段階で保護マスクとして利用できます。すべて緑なら、この描画先のアルファには分離情報がありません。

### 注意

- 診断専用です。色分け表示は仕様です。
- Cinematic DoF Standalone 1.0.2 を上書きしてください。
- ビルド確認済みでも、ゲーム内動作は実機確認が必要です。

## English

### Purpose

Tests 16 and 17 confirmed that neither of the two exterior `flags=0x0C` calls produces a visible buffer delta. The single exterior `flags=0x45` call does react, but its RGB delta mixes the veil with broad scenery updates.

Test18 captures `flags=0x45` both indoors and outdoors and classifies RGB and alpha-channel changes around the player at the same time.

- **Green**: RGB delta only
- **Red**: alpha delta only
- **Yellow**: both RGB and alpha deltas
- **Blue**: neither delta

### What to check

1. Indoors, note the colours on the veil, hair, outfit, and background.
2. Outdoors, note the colours on the veil, hair, outfit, and background.
3. Most importantly, check whether the veil becomes red or yellow while the background remains green or blue.

Please capture one indoor and one outdoor screenshot with the same outfit and a similar framing if possible. If alpha changes only on the veil, it can become the next protection mask. If everything is green, this render target's alpha channel contains no useful separation signal.

### Notes

- This is a diagnostic build; the false colours are intentional.
- Install it over Cinematic DoF Standalone 1.0.2.
- A successful build still requires in-game validation.
