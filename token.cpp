#include "token.h"

Token::Token(const std::string &val, TOKENS ty, int lineNumber)
{
    this -> value = val;
    this -> type = ty;
    this -> line = lineNumber;
}

const std::string& Token::getTokenValue() const 
{
    return this -> value;
}

const TOKENS& Token::getTokenType() const 
{
    return this -> type;
}
int Token::getLineNumber() const 
{
    return this -> line;
}

void Token::printToken() const 
{
    switch(this -> type)
    {
        case TOKEN_IDENTIFIER:
            printf("IDENTIFIER TOKEN ");
            break;
        case TOKEN_ADD:
            printf("ADD TOKEN ");
            break;
        case TOKEN_MINUS:
            printf("MINUS TOKEN ");
            break;
        case TOKEN_DIV:
            printf("DIVISION TOKEN ");
            break;
        case TOKEN_EQUALS:
            printf("EQUALS TOKEN ");
            break;
        case TOKEN_INT:
            printf("INTEGER TOKEN ");
            break;
        case TOKEN_MUL:
            printf("MULTIPLICATION TOKEN ");
            break;
        case TOKEN_SEMICOLON:
            printf("SEMICOLON TOKEN ");
            break;
        case TOKEN_RPAREN:
            printf("RIGHT PARANTHESIS TOKEN ");
            break;
        case TOKEN_LPAREN:
            printf("LEFT PARANTHESIS TOKEN ");
            break;
        case TOKEN_RFBRACKET:
            printf("RIGHT FLOWER BRACKET TOKEN ");
            break;
        case TOKEN_LFBRACKET:
            printf("LEFT FLOWER BRACKET TOKEN ");
            break;
        case TOKEN_LABRACKET:
            printf("LEFT ANGULAR BRACKET TOKEN ");
            break;
        case TOKEN_RABRACKET:
            printf("RIGHT ANGULAR BRACKET TOKEN ");
            break;
        case TOKEN_HASH:
            printf("HASH TOKEN ");
            break;
        case TOKEN_INTDATATYPE:
            printf("INTEGER DATA TYPE TOKEN ");
            break;
        case TOKEN_CHARDATATYPE:
            printf("CHAR DATA TYPE TOKEN ");
            break;
        case TOKEN_DOUBLEDATATYPE:
            printf("DOUBLE DATA TYPE TOKEN ");
            break;
        case TOKEN_STRINGDATATYPE:
            printf("STRING DATA TYPE TOKEN ");
            break;
        default:
            break;
    }
    printf("%s %d\n", this -> value.c_str(), this -> getLineNumber());
}
