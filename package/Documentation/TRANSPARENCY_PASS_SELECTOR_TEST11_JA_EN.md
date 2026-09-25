# Transparency Pass Selector Diagnostic Test 11

## 日本語

この診断版は、1フレーム内で複数回呼ばれる透明描画のうち、指定した順番の1回だけを採取します。通常の `CinematicDoFStandalone.ini` は変更しません。

設定ファイル：

`Data/SKSE/Plugins/CinematicDoFStandalone-TransparencyTest11.ini`

`PassIndex=1` を `2`、`3`、`4`…へ変更し、その都度Skyrimを完全に終了してから再起動してください。まず1～6を、同じ屋内と屋外の構図で確認してください。色が出た番号と場所を記録してください。連続した上位番号で変化がなくなった場合は、そこで終了して構いません。

ログ `Documents/My Games/Skyrim Special Edition/SKSE/CinematicDoFStandalone.log` には、選択番号と、ポストプロセス前に観測した透明描画呼び出し数の最大値が記録されます。

この版は診断専用です。Test 20の白膜・空・月修正版とは別ブランチであり、完成版として常用しないでください。

## English

This diagnostic captures only the selected ordinal transparency-renderer call when the engine invokes that routine multiple times in one frame. It does not modify the normal `CinematicDoFStandalone.ini`.

Edit `Data/SKSE/Plugins/CinematicDoFStandalone-TransparencyTest11.ini`, change `PassIndex=1` to `2`, `3`, `4`, and so on, and fully restart Skyrim after each change. Test indices 1 through 6 first with the same interior and exterior compositions. Record which indices produce diagnostic color and where. You may stop after consecutive higher indices show no change.

The SKSE log records the selected index and the largest number of transparency calls observed before one post-processing frame.

This is a diagnostic build, kept separate from the Test 20 sky/foliage/moon fix. Do not use it as the final production build.
