#pragma once
#include <string>
#include "lexer.h"
#include "parseTree.h"
class Compiler 
{
    private:
        std::string sourceText;
    public:
        Compiler(const std::string &source);
        Compiler(FILE *fptr);

        void compileSourceText();
};