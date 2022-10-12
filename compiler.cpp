#include "compiler.h"

Compiler::Compiler(const std::string &source)
{
    this -> sourceText = source;
}
Compiler::Compiler(FILE *fptr)
{
    this -> sourceText = Lexer::generateStringFromFile(fptr);
    //std::cout << this -> sourceText << std::endl;
}
void Compiler::compileSourceText()
{
    Lexer *lexer = new Lexer(this -> sourceText);
    lexer -> lexTokens();
    lexer -> printLexedTokens();
    parseTree *parser = new parseTree(lexer -> getLexedTokens());
    parser -> buildTreeFromTokens();
    parser -> printTree();
}