# GLSLANG

include file : `Public/ShaderLang.h`
 
## Enum type list
---
| type | override |
| --- | --- |
| EShLanguage | コンパイラーが使用できる言語のタイプ。 |
| EShLanguageMask | EShLanguageのマスク情報 |
| EShSource | EShLanguageがEShStageの場合、これは代わりにEShLanguageである可能性があります |
| EShClient | クライアントがない場合の検証用の宣言 |
| EShTargetLanguage |  |
| EShTargetClientVersion | VulkanのバージョンとOpenGL4のバージョン指定。 |
| EShTargetLanguageVersion | SPIR-Vのバージョン指定 |
| EShExecutable | リンカが作成する出力のタイプ。 |
| EShOptimizationLevel | コンパイラーの最適化レベル。 |
| EShTextureSamplerTransformMode | テクスチャとサンプラーの変換モード。 |
| EShMessages | 表示されるエラーと警告に関するメッセージの選択。 |
| EShReflectionOptions | リフレクションを構築するためのオプション |
| TResourceType | IOリゾルバーのリソースタイプ |


## C lnterface
---
| name | override | return |
| --- | --- | --- |
| ShInitialize() | Call before doing any other compiler/linker operations. | int |
| ShFinalize() | Call this at process shutdown to clean up memory. | int |
| StageName(EShLanguage) | | const char* |
| ShConstructCompiler(const EShLanguage, int debugOptions) | | ShHandle |
| ShConstructLinker(const EShExecutable, int debugOptions) | | ShHandle |
| ShConstructUniformMap() | |ShHandle |
| ShDestruct(ShHandle) | | void |
| ShLinkExt(const ShHandle, const ShHandle[], const int) | | int |
| ShSetEncryptionMethod(ShHandle) | ShSetEncrpytionMethodは、指定するためのプレースホルダーです。ソースコードの暗号化方法。 | void |
| ShGetInfoLog(const ShHandle) | | const char* |
| ShGetExecutable(const ShHandle) | | const void* |
| ShSetVirtualAttributeBindings(const ShHandle, const ShBindingTable*) | | int |
| ShSetFixedAttributeBindings(const ShHandle, const ShBindingTable*) | | int |
| ShExcludeAttributes(const ShHandle, int *attributes, int count) | この物理属性のリストに頂点属性を割り当てないようにリンカーに指示します | int |
| ShGetUniformLocation(const ShHandle uniformMap, const char* name) | 名前付きユニフォームのロケーションIDを返します。エラーの場合は-1を返します。 | int |
| ShCompile(const ShHandle, const char* const[], const int, const int*, const EShOptimizationLevel, const TBuiltInResource, int, int=110, bool=false, EShMessages=EShMsgDefault) | | int |

## C++ Interface
---
| name | return | override |
| --- | --- | --- |
| glslang::GetVersion | struct Version | |
| glslang::GetEsslVersionString | const char* | |
| glslang::GetGlslVersionString | const char* | |
| glslang::GetKhronosToolId | int | |
| glslang::InitializeProcess | bool | |
| glslang::FinalizeProcess | void | |

## STRUCT list
---
| struct name | override |
| --- | --- |
| TInputLanguage | |
| TClient | |
| TTarget | |
| TEnvironment | すべてのソース/クライアント/ターゲットのバージョンと設定。 |
| ShBinding | バインディング用のテーブルを作成します。 これは、場所を特定するために使用できます |
| ShBindingTable | |

## CLASS list
---
namespace `glslang`

| class name | override |
| --- | --- |
| TProgram | 一緒にリンクされるシェーダーのセットごとに1つのTProgramを作成します。 |
| TIoMapResolver | リンク後にバインディングレイアウトをカスタマイズできます。 |
| TObjectReflection | A reflection database and its interface, consistent with the OpenGL API reflection queries. Data needed for just a single object at the granularity exchanged by the reflection API. |
| TShader | プログラムにリンクするシェーダーごとに1つのTShaderを作成します。|
| TShader::Includer | includeハンドラーへのインターフェース。 |
| TShader::Includer::IncludeResult | IncludeResultには、解決されたソースの名前とコンテンツが含まれます |
| TShader::ForbidIncluder | すべてのインクルーダー検索に失敗する。 |
