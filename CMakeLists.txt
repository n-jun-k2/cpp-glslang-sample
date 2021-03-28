cmake_minimum_required(VERSION 3.8)

project(GlslangSample)

set(GLSLANGLIBS
    GenericCodeGen
    glslang
    HLSL
    MachineIndependent
    OGLCompiler
    OSDependent
    SPIRV
    SPVRemapper
    SPIRV-Tools
    SPIRV-Tools-opt
    SPIRV-Tools-link
    SPIRV-Tools-reduce
    SPIRV-Tools-shared
)

file(
    GLOB_RECURSE
    SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

include_directories(
    $ENV{VULKAN_SDK}/include
)

link_directories(
    $ENV{VULKAN_SDK}/Lib
)

add_executable(
    ${PROJECT_NAME} 
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    ${GLSLANGLIBS}
)
# PDBの警告対応
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/ignore:4099")

target_compile_options(
    ${PROJECT_NAME} PRIVATE
    "/MD"
)

target_compile_features(
    ${PROJECT_NAME} PRIVATE
    cxx_std_17
)