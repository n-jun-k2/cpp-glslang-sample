# cpp-glslang-sample
Sample project for running GLS Lang project under Windows environment.

[Reference](https://github.com/KhronosGroup/glslang)

## Required software
- [Visual Studo 2019 (Install all "Desktop development with C ++")](https://visualstudio.microsoft.com/ja/downloads/)
- [CMake (3.20.0-rc5)](https://cmake.org/download/)
- [Vulkan SDK](https://vulkan.lunarg.com/)

## Hot to use...

```bash

# Cmake build (Debug)
> make build
cmake -S . -B ./build -G "Visual Studio 16 2019" -A x64
-- The C compiler identification is MSVC 19.28.29913.0
-- The CXX compiler identification is MSVC 19.28.29913.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done

...

  Building Custom Rule C:/work/cpp-glslang-sample/CMakeLists.txt

```