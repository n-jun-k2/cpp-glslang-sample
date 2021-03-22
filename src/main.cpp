#include <iostream>
#include <glslang/Public/ShaderLang.h>


int main () {
    glslang::InitializeProcess();
    {
        std::cout << "HELLO GLSLang" << std::endl;
        std::cout << "GLSL Version :" << glslang::GetGlslVersionString() << std::endl;
    }
    glslang::FinalizeProcess();
}