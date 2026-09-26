# Transparency Player Shader Geometry Diagnostic Test23

## 日本語

これは透過対応の完成版ではなく、診断専用ビルドです。

Test22では画面内に緑・黄色・マゼンタが現れず、`NiAlphaProperty` を条件にしたプレイヤーメッシュ境界を取得できていないことが分かりました。Test23は原因を二つに分離します。

1. プレイヤー3Dツリー内の全ての可視 `BSGeometry` を取得できているか
2. その中で、`NiAlphaProperty`、シェーダーフラグ、`BSShaderProperty::alpha`、またはライティングマテリアルの `materialAlpha` から透過候補を見つけられるか

境界数の上限は各32件です。通常のDoF合成は変更していません。

色の意味：

- **緑**：RGB変化あり、プレイヤー配下の透過候補Geometry境界内
- **黄色**：RGB変化あり、プレイヤー配下のGeometry境界内だが透過候補ではない
- **シアン**：RGB変化あり、全プレイヤーGeometry境界の外
- **マゼンタ**：RGB変化なし、ただしプレイヤーGeometry境界内
- **青**：RGB変化なし、プレイヤーGeometry境界外

特に次を確認してください。

- 人物本体や衣装に黄色または緑が出るか
- 白いベール、髪、ドレスの裾・トレーンが緑になるか
- 家具、窓、植物、空、地形がシアンまたは青のままか

判定：

- **黄色またはマゼンタが出る**：プレイヤーGeometryの探索は成功しています。緑の出方から透過属性の候補を評価できます。
- **緑だけが広く出る**：シェーダー候補条件が広すぎます。次にフラグを個別分類します。
- **今回もシアン／青だけ**：`Actor::Get3D()` から辿るツリーが、実際に描画された装備Geometryを含んでいません。次は装備側3Dまたは描画パスから所有者を追います。

ログには `candidate bounds`、`all geometry bounds`、`classic alpha geometries`、`shader/material alpha geometries` が1回出力されます。可能ならスクリーンショットと一緒にその行も共有してください。

## English

This is a diagnostic build, not the finished transparency fix.

Test22 produced no green, yellow, or magenta pixels, showing that no usable player mesh bounds were found through `NiAlphaProperty`. Test23 separates two possible causes:

1. Whether all visible `BSGeometry` objects in the player's 3D tree can be found
2. Whether transparency candidates can be identified through `NiAlphaProperty`, shader flags, `BSShaderProperty::alpha`, or lighting-material `materialAlpha`

Each bound list is capped at 32 entries. Normal DoF composition is unchanged.

Colour key:

- **Green**: RGB changed inside a player-owned transparency-candidate geometry bound
- **Yellow**: RGB changed inside another player-owned geometry bound
- **Cyan**: RGB changed outside all player geometry bounds
- **Magenta**: no RGB change, but inside a player geometry bound
- **Blue**: no RGB change and outside all player geometry bounds

Please check whether the actor or outfit produces yellow or green, whether the white veil, hair, dress hem, and train become green, and whether furniture, windows, foliage, sky, and terrain remain cyan or blue.

Interpretation:

- **Yellow or magenta appears**: player geometry traversal works; the green coverage evaluates the transparency hints.
- **Only broad green appears**: the shader candidate rule is too broad and should be split by individual flag next.
- **Still only cyan and blue**: the tree reached through `Actor::Get3D()` does not contain the equipment geometry that was actually rendered. The next step is to follow equipped-object 3D or ownership from the render pass.

The log prints one line containing `candidate bounds`, `all geometry bounds`, `classic alpha geometries`, and `shader/material alpha geometries`. If possible, share that line with the screenshots.
