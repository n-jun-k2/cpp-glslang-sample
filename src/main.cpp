#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>

static TBuiltInResource InitResources() noexcept
{
    TBuiltInResource Resources;

    Resources.maxLights                                 = 32;
    Resources.maxClipPlanes                             = 6;
    Resources.maxTextureUnits                           = 32;
    Resources.maxTextureCoords                          = 32;
    Resources.maxVertexAttribs                          = 64;
    Resources.maxVertexUniformComponents                = 4096;
    Resources.maxVaryingFloats                          = 64;
    Resources.maxVertexTextureImageUnits                = 32;
    Resources.maxCombinedTextureImageUnits              = 80;
    Resources.maxTextureImageUnits                      = 32;
    Resources.maxFragmentUniformComponents              = 4096;
    Resources.maxDrawBuffers                            = 32;
    Resources.maxVertexUniformVectors                   = 128;
    Resources.maxVaryingVectors                         = 8;
    Resources.maxFragmentUniformVectors                 = 16;
    Resources.maxVertexOutputVectors                    = 16;
    Resources.maxFragmentInputVectors                   = 15;
    Resources.minProgramTexelOffset                     = -8;
    Resources.maxProgramTexelOffset                     = 7;
    Resources.maxClipDistances                          = 8;
    Resources.maxComputeWorkGroupCountX                 = 65535;
    Resources.maxComputeWorkGroupCountY                 = 65535;
    Resources.maxComputeWorkGroupCountZ                 = 65535;
    Resources.maxComputeWorkGroupSizeX                  = 1024;
    Resources.maxComputeWorkGroupSizeY                  = 1024;
    Resources.maxComputeWorkGroupSizeZ                  = 64;
    Resources.maxComputeUniformComponents               = 1024;
    Resources.maxComputeTextureImageUnits               = 16;
    Resources.maxComputeImageUniforms                   = 8;
    Resources.maxComputeAtomicCounters                  = 8;
    Resources.maxComputeAtomicCounterBuffers            = 1;
    Resources.maxVaryingComponents                      = 60;
    Resources.maxVertexOutputComponents                 = 64;
    Resources.maxGeometryInputComponents                = 64;
    Resources.maxGeometryOutputComponents               = 128;
    Resources.maxFragmentInputComponents                = 128;
    Resources.maxImageUnits                             = 8;
    Resources.maxCombinedImageUnitsAndFragmentOutputs   = 8;
    Resources.maxCombinedShaderOutputResources          = 8;
    Resources.maxImageSamples                           = 0;
    Resources.maxVertexImageUniforms                    = 0;
    Resources.maxTessControlImageUniforms               = 0;
    Resources.maxTessEvaluationImageUniforms            = 0;
    Resources.maxGeometryImageUniforms                  = 0;
    Resources.maxFragmentImageUniforms                  = 8;
    Resources.maxCombinedImageUniforms                  = 8;
    Resources.maxGeometryTextureImageUnits              = 16;
    Resources.maxGeometryOutputVertices                 = 256;
    Resources.maxGeometryTotalOutputComponents          = 1024;
    Resources.maxGeometryUniformComponents              = 1024;
    Resources.maxGeometryVaryingComponents              = 64;
    Resources.maxTessControlInputComponents             = 128;
    Resources.maxTessControlOutputComponents            = 128;
    Resources.maxTessControlTextureImageUnits           = 16;
    Resources.maxTessControlUniformComponents           = 1024;
    Resources.maxTessControlTotalOutputComponents       = 4096;
    Resources.maxTessEvaluationInputComponents          = 128;
    Resources.maxTessEvaluationOutputComponents         = 128;
    Resources.maxTessEvaluationTextureImageUnits        = 16;
    Resources.maxTessEvaluationUniformComponents        = 1024;
    Resources.maxTessPatchComponents                    = 120;
    Resources.maxPatchVertices                          = 32;
    Resources.maxTessGenLevel                           = 64;
    Resources.maxViewports                              = 16;
    Resources.maxVertexAtomicCounters                   = 0;
    Resources.maxTessControlAtomicCounters              = 0;
    Resources.maxTessEvaluationAtomicCounters           = 0;
    Resources.maxGeometryAtomicCounters                 = 0;
    Resources.maxFragmentAtomicCounters                 = 8;
    Resources.maxCombinedAtomicCounters                 = 8;
    Resources.maxAtomicCounterBindings                  = 1;
    Resources.maxVertexAtomicCounterBuffers             = 0;
    Resources.maxTessControlAtomicCounterBuffers        = 0;
    Resources.maxTessEvaluationAtomicCounterBuffers     = 0;
    Resources.maxGeometryAtomicCounterBuffers           = 0;
    Resources.maxFragmentAtomicCounterBuffers           = 1;
    Resources.maxCombinedAtomicCounterBuffers           = 1;
    Resources.maxAtomicCounterBufferSize                = 16384;
    Resources.maxTransformFeedbackBuffers               = 4;
    Resources.maxTransformFeedbackInterleavedComponents = 64;
    Resources.maxCullDistances                          = 8;
    Resources.maxCombinedClipAndCullDistances           = 8;
    Resources.maxSamples                                = 4;
    Resources.maxMeshOutputVerticesNV                   = 256;
    Resources.maxMeshOutputPrimitivesNV                 = 512;
    Resources.maxMeshWorkGroupSizeX_NV                  = 32;
    Resources.maxMeshWorkGroupSizeY_NV                  = 1;
    Resources.maxMeshWorkGroupSizeZ_NV                  = 1;
    Resources.maxTaskWorkGroupSizeX_NV                  = 32;
    Resources.maxTaskWorkGroupSizeY_NV                  = 1;
    Resources.maxTaskWorkGroupSizeZ_NV                  = 1;
    Resources.maxMeshViewCountNV                        = 4;

    Resources.limits.nonInductiveForLoops                 = 1;
    Resources.limits.whileLoops                           = 1;
    Resources.limits.doWhileLoops                         = 1;
    Resources.limits.generalUniformIndexing               = 1;
    Resources.limits.generalAttributeMatrixVectorIndexing = 1;
    Resources.limits.generalVaryingIndexing               = 1;
    Resources.limits.generalSamplerIndexing               = 1;
    Resources.limits.generalVariableIndexing              = 1;
    Resources.limits.generalConstantMatrixVectorIndexing  = 1;

    return Resources;
}

template<template<typename E, typename Allocator=std::allocator<E>>typename Container>
static void readFile(const std::string& filePath, Container<char>& buffer) {
  std::ifstream file(filePath, std::ios::ate | std::ios::in);
  if (!file.is_open())
    throw std::runtime_error("failed to open file!");

  auto fileSize = (size_t)file.tellg();
  buffer.resize(fileSize);
  file.seekg(0);
  file.read(buffer.data(), fileSize);
  file.close();
}


int main () try {

  auto version = glslang::GetVersion();

  std::cout << "GLSLang version :"<< version.major << "." << version.minor << "." << version.patch << "." << version.flavor << std::endl;
  std::cout << "ELSL Version :" << glslang::GetEsslVersionString() << std::endl;
  std::cout << "GLSL Version :" << glslang::GetGlslVersionString() << std::endl;

  std::string spirvVersion;
  glslang::GetSpirvVersion(spirvVersion);
  std::cout << "SPIRV Version :" << spirvVersion << std::endl;
  std::cout << "SPIRV Generator Version :" << glslang::GetSpirvGeneratorVersion() << std::endl;

  bool isInitilize =  glslang::InitializeProcess();
  std::cout << "initilize process :" << isInitilize << std::endl;
  if(!isInitilize) {
    throw std::runtime_error("Failed to initialize the process.");
  }

  const std::filesystem::path vertFilePath = "shaders\\GLSL\\vert\\sample.vert";

  // Load a shader file
  std::vector<char> vertFile;
  readFile(vertFilePath.generic_string(), vertFile);
  std::string strVertBuffer(vertFile.begin(), vertFile.end());
  std::cout << "vertex file size. :" << vertFile.size() << std::endl;

  // Vertex shader object
  auto targetStage = EShLanguage::EShLangVertex;
  glslang::TShader shaderObject(targetStage);

  // TShader settings
  std::vector<const char*> pTempShaderSrc {
    strVertBuffer.c_str()
  };
  shaderObject.setStrings(pTempShaderSrc.data(), static_cast<int>(pTempShaderSrc.size()));

  // The input source language and stage.
  shaderObject.setEnvInput(glslang::EShSource::EShSourceGlsl, targetStage, glslang::EShClient::EShClientVulkan, glslang::EShTargetClientVersion::EShTargetVulkan_1_2);

  // Specify the version of the client environment to run.
  shaderObject.setEnvClient(glslang::EShClient::EShClientVulkan, glslang::EShTargetClientVersion::EShTargetVulkan_1_2);


  shaderObject.setEnvTarget(glslang::EShTargetLanguage::EShTargetSpv, glslang::EShTargetLanguageVersion::EShTargetSpv_1_4);

  auto message = static_cast<EShMessages>(EShMsgSpvRules | EShMsgVulkanRules);

  TBuiltInResource builtinResource = InitResources();
  auto isParse = shaderObject.parse(&builtinResource, 100, false, message);
  std::cout << "parse status : " << isParse << std::endl;
  if(!isParse) {
    std::cout << shaderObject.getInfoLog() << std::endl;
    std::cout << shaderObject.getInfoDebugLog() << std::endl;
    throw std::runtime_error("failed to parse.");
  }

  glslang::TProgram program;
  program.addShader(&shaderObject);
  auto isLink = program.link(message);
  std::cout << "link status : " << isLink << std::endl;
  if(!isLink) {
    std::cout << program.getInfoLog() << std::endl;
    std::cout << program.getInfoDebugLog() << std::endl;
    throw std::runtime_error("failed to program Link.");
  }

  std::vector<uint32_t> outSPV;

  glslang::SpvOptions spvOptions;

  spvOptions.generateDebugInfo = true;
  spvOptions.disableOptimizer = false;
  spvOptions.optimizeSize = false;

  glslang::GlslangToSpv(*program.getIntermediate(targetStage), outSPV, &spvOptions);

  std::cout << "SPV data size:" << static_cast<uint64_t>(outSPV.size()) << std::endl;

  glslang::FinalizeProcess();

  return 1;

} catch (std::runtime_error err) {
  std::cerr << "runtime_error : " << err.what() << std::endl;
  glslang::FinalizeProcess();
} catch (...) {
  std::cerr << "faild to proguram" << std::endl;
  glslang::FinalizeProcess();
}