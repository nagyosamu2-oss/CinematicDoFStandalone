# Transparency Player Alpha Geometry Diagnostic Test22

## 日本語

これは透過対応の完成版ではなく、診断専用ビルドです。

Test21では、人物本体はプレイヤー深度として分かれましたが、透明なベールやトレーンは、その背後にある物体の深度として分類されました。これにより、透明装備自身は主深度へ固有の値を書かず、主深度だけでは装備と背景を区別できないことが確認できました。

Test22は深度を分類条件に使いません。プレイヤーの3Dツリーを調べ、`NiAlphaProperty` を持つメッシュの画面上の境界を投影します。プレイヤーへ装着された透過メッシュはこのツリーの内側にあり、室内のガラス・照明・置物や屋外の植物・地形は外側にある、という所属関係を検証します。

色の意味：

- **緑**：RGB変化あり、プレイヤー配下のアルファブレンド・メッシュ境界内
- **黄色**：RGB変化あり、プレイヤー配下のアルファテスト専用メッシュ境界内
- **シアン**：RGB変化あり、どちらのプレイヤー透過メッシュ境界にも入らない
- **マゼンタ**：RGB変化なし、ただしプレイヤー透過メッシュ境界内
- **青**：RGB変化なし、プレイヤー透過メッシュ境界外

白いベール、髪、ドレスの裾・トレーンが緑または黄色になり、家具・窓・ガラス・植物・空・地形がシアンまたは青のままかを確認してください。マゼンタが大きく広がる場合は、メッシュの境界球が実物より広すぎることを示します。

この段階では境界球による近似です。緑や黄色が目的の装備へ十分沿えば、次に実際の保護マスクへ使える形へ絞ります。通常のDoF合成は変更していません。

## English

This is a diagnostic build, not the finished transparency fix.

Test21 separated the opaque character body at player depth, but classified the transparent veil and train by the depth of whatever was behind them. This confirms that transparent equipment does not provide its own useful value in the main depth buffer, so main depth alone cannot distinguish it from the background.

Test22 does not use depth as its classifier. It walks the player's 3D scenegraph and projects the screen-space bounds of meshes carrying `NiAlphaProperty`. Equipped transparent meshes belong to the player tree, while room glass, lights, props, outdoor foliage, and terrain do not. This test checks that ownership distinction.

Colour key:

- **Green**: RGB changed inside a player-owned alpha-blended mesh bound
- **Yellow**: RGB changed inside a player-owned alpha-test-only mesh bound
- **Cyan**: RGB changed outside all player-owned alpha mesh bounds
- **Magenta**: no RGB change, but inside a player-owned alpha mesh bound
- **Blue**: no RGB change and outside the player-owned alpha mesh bounds

Please check whether the white veil, hair, dress hem, and train become green or yellow while furniture, windows, glass, foliage, sky, and terrain remain cyan or blue. Large magenta areas mean a mesh bounding sphere is substantially broader than the visible mesh.

This stage still uses bounding-sphere approximations. If green or yellow follows the target equipment closely enough, the next step can refine it into a real protection mask. Normal DoF composition is unchanged.
