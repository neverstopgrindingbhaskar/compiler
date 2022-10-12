#include "compiler.h"
#include <string>

int main()
{
    std::string sourcePath = "test/basicadd.c";
    FILE *fptr;
    fptr = fopen(sourcePath.c_str(), "r");
    Compiler *cp = new Compiler(fptr);
    cp -> compileSourceText();
    return 0;
}