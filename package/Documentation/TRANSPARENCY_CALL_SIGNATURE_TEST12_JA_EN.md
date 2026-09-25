# Transparency Call Signature Diagnostic Test 12

## 日本語

この診断版は、透明描画フックの呼び出しを描画フラグ、描画モード、active、一人称、decal状態ごとに固定長で集計します。Test11の水色表示やGPUテクスチャ採取は行いません。

1. 屋内で通常のゲーム画面を1秒以上表示します。
2. 屋外へ移動し、通常のゲーム画面を1秒以上表示します。
3. Skyrimを終了します。
4. `Documents/My Games/Skyrim Special Edition/SKSE/CinematicDoFStandalone.log` を共有してください。

ログには安定した屋内・屋外フレームが各1回だけ `Test12 INTERIOR` / `Test12 EXTERIOR` として記録されます。画像や動画は、見た目に異常がなければ不要です。

この版は診断専用です。Test20の白膜・空・月修正版とは別ブランチであり、完成版として常用しないでください。

## English

This diagnostic groups transparency-hook calls by render flags, render mode, active state, first-person state, and decal state using fixed-capacity storage. It performs neither the cyan Test11 visualization nor GPU texture capture.

1. Show normal gameplay indoors for at least one second.
2. Move outdoors and show normal gameplay for at least one second.
3. Exit Skyrim.
4. Share `Documents/My Games/Skyrim Special Edition/SKSE/CinematicDoFStandalone.log`.

The log records one stable `Test12 INTERIOR` frame and one stable `Test12 EXTERIOR` frame. Screenshots or video are unnecessary unless the build causes a visible problem.

This is a diagnostic build, kept separate from the Test20 sky/foliage/moon fix. Do not use it as the final production build.
