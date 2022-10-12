#pragma once
#include <string>
#include "token.h"
#include "util.h"
#include <iostream>
#include <vector>
class Lexer 
{
    private:
        std::string sourceText;
        char currentChar;
        int currentCharIndex;
        int sourceTextSize;
        int lineNumber;
        bool advanceLexer();
        
        enum ExpectLexerTypes {
                                LEXERTYPE_CHAR,
                                LEXERTYPE_INT,
                                LEXERTYPE_SEMICOLON,
                                LEXERTYPE_OPERATOR
                              };
        Token getTokenFromCurrentChar();
        std::string getStringFromCurrentChar();
        std::string eatTokens(ExpectLexerTypes lexerType);
        std::string eatInteger();
        std::string eatChar();
        std::string eatOperator();
        std::vector <Token> lexedTokens;
    public:
        Lexer(const std::string &source);
        static std::string generateStringFromFile(FILE *fptr);
        void lexTokens();
        void skipWhiteSpace();
        void printLexedTokens();
        std::vector <Token> getLexedTokens();
};