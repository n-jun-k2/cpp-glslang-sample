# SPIRV

include files
- `SPIRV/GlslangToSpv.h`
- `SPIRV/Logger.h`
- `SPIRV/spirv.hpp`
- `SPIRV/spvIR.h`
- `SPIRV/SPVRemapper.h`
- `SPIRV/SpvTools.h`

## ENUM list
---

file : `spirv.hpp`

| enum name | override |
| --- | --- |
| SourceLanguage | |
| ExecutionModel | |
| AddressingModel | |
| MemoryModel | |
| ExecutionMode | |
| StorageClass | |
| Dim | |
| SamplerAddressingMode | |
| SamplerFilterMode | |
| ImageFormat | |
| ImageChannelOrder | |
| ImageChannelDataType | |
| ImageOperandsShift | |
| ImageOperandsMask | |
| FPFastMathModeShift | |
| FPFastMathModeMask | |
| FPRoundingMode | |
| LinkageType | |
| AccessQualifier | |
| FunctionParameterAttribute | |
| Decoration | |
| BuiltIn | |
| SelectionControlShift | |
| SelectionControlMask | |
| LoopControlShift | |
| LoopControlMask | |
| FunctionControlShift | |
| FunctionControlMask | |
| MemorySemanticsShift | |
| MemorySemanticsMask | |
| MemoryAccessShift | |
| MemoryAccessMask | |
| Scope | |
| GroupOperation | |
| KernelEnqueueFlags | |
| KernelProfilingInfoShift | |
| KernelProfilingInfoMask | |
| Capability | |
| RayFlagsShift | |
| RayFlagsMask | |
| RayQueryIntersection | |
| RayQueryCommittedIntersectionType | |
| RayQueryCandidateIntersectionType | |
| Op | |

## C++ interface

namespace `glslang`
---

file : `GlslangToSpv.h`

| function name | return | override |
| --- | --- | --- |
| GetSpirvVersion(std::string&) | void | |
| GetSpirvGeneratorVersion() | int | |
| GlslangToSpv(const glslang::TIntermediate&, std::vector<unsigned int>& , SpvOptions*=nullptr)| void | |
| GlslangToSpv(const glslang::TIntermediate&, std::vector<unsigned int>&, spv::SpvBuildLogger*, SpvOptions*=nullptr) | void | |
| OutputSpvBin(const std::vector<unsigned int>&, const char*) | void | |
| OutputSpvHex(const std::vector<unsigned int>&, const char*, const char*) | void | |


## CLASS list
---
namespace `spv`

| class name | file | override |
|--- | --- | --- |
| spirvbin_t | SPVRemapper.h | リマップ、DCE、デバッグストリッピング用のSPIR-Vバイナリデータを保持するクラス |
| Instruction | spvIR.h | SPIR-VのIRインストラクション |
| Block | spvIR.h | SPIR-VのIRブロック |
| Function | spvIR.h | SPIR-VのIR関数 |
| Module | spvIR.h | SPIR-VのIRモジュール。 |
| SpvBuildLogger | Logger.h | すべての SPIR-V ビルドステータスメッセージを保持するクラス |

## STRUCT list
---

namepsace `glslang`

| struct name | file | override |
| --- | --- | --- |
| SpvOptions | SpvTools.h | |

### namespace `spv`

| struct name | file | override |
| --- | --- | --- |
| IdImmediate | spvIR.h | |
