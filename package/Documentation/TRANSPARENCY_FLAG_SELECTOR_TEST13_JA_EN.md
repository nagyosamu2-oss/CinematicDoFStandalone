# Transparency Flag Selector Diagnostic Test 13

## 日本語

Test12の屋内・屋外ログで共通して確認できた透明描画 `flags=0x45` の前後だけを採取します。呼び出し順には依存しないため、屋外で先に実行される別用途の `flags=0x0C` は除外されます。

同じベールを装備した状態で、屋内と屋外の両方を確認してください。正常なら両方で水色の診断表示が現れます。特に、ベール本体と裾・後方へ伸びる透過部分が反応するかを確認してください。

通常の `CinematicDoFStandalone.ini` は変更しません。結果は屋内・屋外それぞれの画像があると比較しやすくなります。

この版は診断専用です。Test20の白膜・空・月修正版とは別ブランチです。

## English

This build captures only around transparency rendering with `flags=0x45`, the signature shared by the stable interior and exterior frames from Test12. It does not depend on ordinal call order, so the unrelated `flags=0x0C` calls that precede it outdoors are ignored.

With the same veil equipped, test both indoors and outdoors. A successful result should show the cyan diagnostic visualization in both locations. Check the veil body and its trailing transparent sections in particular.

The normal `CinematicDoFStandalone.ini` is not changed. One interior and one exterior screenshot make the result easiest to compare.

This is a diagnostic build kept separate from the Test20 sky/foliage/moon fix.
