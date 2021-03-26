# MachineIndependent

TIntermediateのためのいくつかのヘルパー構造。
これらのコンテンツはTIntermediateによってカプセル化されます。

include files
- `MachineIndependent/localintermediate`
- `MachineIndependent/Versions.h`

## Enum list:

| enum name | override |
| --- | --- |
| ComputeDerivativeMode | テクスチャとサンプラーの変換モードの定義 |

## Struct lsit:

| struct name | override |
| --- | --- |
| TMatrixSelector | 列/行にとらわれないでください。これは解析順序です |
| TCall | コールグラフ・アルゴリズムに使用されます。 |
| TRange | 1次元の範囲の開始値と終了値が格納されている |
| TIoRange | 3次元の範囲オブジェクト. 空間(ロケーションの1次元範囲、コンポーネントの1次元範囲、インデックスの値)内にある指標値オブジェクト。 |
| TOffsetRange | 2次元の範囲オブジェクト. 平面(バインディング、 オフセット)内にある指標値オブジェクト。 |
| TXfbBuffer | xfbのバッファごとにトラッキングが必要なオブジェクト |
| TProcesses | モジュールがどのように処理されたかを記述した文字列オブジェクト|

## Class list:

| class name | override |
| --- | --- |
| TSwizzleSelectors<typename selectorType> | |
| TIdMaps | TMap<TString, int>の配列オブジェクト. getter/setterのみ |
| TNumericFeatures | シェーダー機能の状態を表すオブジェクト。|
| TIntermediate | |