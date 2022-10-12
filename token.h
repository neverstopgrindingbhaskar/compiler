#include <string>
#pragma once
enum TOKENS
            {
            TOKEN_INT,
            TOKEN_EQUALS, 
            TOKEN_LPAREN, 
            TOKEN_RPAREN, 
            TOKEN_LFBRACKET, 
            TOKEN_RFBRACKET,
            TOKEN_ADD,
            TOKEN_SEMICOLON,
            TOKEN_MINUS,
            TOKEN_MUL,
            TOKEN_DIV,
            TOKEN_IDENTIFIER,
            TOKEN_LABRACKET,
            TOKEN_RABRACKET,
            TOKEN_HASH,
            TOKEN_INTDATATYPE,
            TOKEN_CHARDATATYPE,
            TOKEN_DOUBLEDATATYPE,
            TOKEN_STRINGDATATYPE,
            TOKEN_NULL
            };

class Token 
{
    enum DataTypes
    {
        INT,
        FLOAT,
        DOUBLE,
        STRING,
        CHAR,
    };
    private:
        TOKENS type;
        std::string value;
        int line;
    public:
        Token(const std::string &val, TOKENS ty, int lineNumber);
        const std::string &getTokenValue() const;
        const TOKENS &getTokenType() const;
        int getLineNumber() const;
        void printToken() const;
};