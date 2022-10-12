#include "lexer.h"
//! initializes the Lexer
Lexer::Lexer(const std::string &source)
{
    this -> sourceTextSize = source.size();
    this -> sourceText = source;
    this -> currentCharIndex = 0;
    this -> currentChar = this -> sourceText[this -> currentCharIndex];
    this -> lineNumber = 0;
}
//! generates string from given file ptr
std::string Lexer::generateStringFromFile(FILE *fptr)
{
    std::string content;
    char ch;
    while(1)
    {
        ch = fgetc(fptr);
        if(ch == EOF)
        break;
        content += ch;
    }
    return content;
}
//! increments the currentCharIndex and updates
//! current character
bool Lexer::advanceLexer()
{
    this -> currentCharIndex += 1;
    if(this -> currentCharIndex < this -> sourceTextSize)
    {
        this -> currentChar = this -> sourceText[this -> currentCharIndex];
        
        return true;
    }
    return false;
}
std::string Lexer::eatInteger()
{
    std::string currentString;
    while(isdigit(this -> currentChar))
    {
        currentString += this -> currentChar;
        if(!advanceLexer())
        break;
    }
    return currentString;
}

std::string Lexer::eatChar()
{
    std::string currentString;
    while(isalpha(this -> currentChar))
    {
        currentString += this -> currentChar;
        if(!advanceLexer())
        break;
    }
    return currentString;
}
std::string Lexer::eatOperator()
{
    std::string currentString;
    currentString = this -> currentChar;
    advanceLexer();
    return currentString;
}
std::string Lexer::eatTokens(ExpectLexerTypes lexerType)
{
    if(lexerType == ExpectLexerTypes::LEXERTYPE_CHAR)
    {
        return eatChar();
    }
    else if(lexerType == ExpectLexerTypes::LEXERTYPE_INT)
    {
        return eatInteger();
    }
    else
    {
        return eatOperator();
    }
}
//! get all characters to a string to return
std::string Lexer::getStringFromCurrentChar()
{
    if(isalpha(this -> currentChar))
    return eatTokens(ExpectLexerTypes::LEXERTYPE_CHAR);
    else if(isdigit(this -> currentChar))
    return eatTokens(ExpectLexerTypes::LEXERTYPE_INT);
    return eatTokens(ExpectLexerTypes::LEXERTYPE_OPERATOR);
}

Token Lexer::getTokenFromCurrentChar()
{
    std::string currentString = getStringFromCurrentChar();
    
    if(TypeChecker::isStringANumber(currentString))
    {
        return Token(currentString, TOKENS::TOKEN_INT, this -> lineNumber);
    }
    else if(TypeChecker::isStringAnOperator(currentString))
    {
        if(currentString == "+")
        return Token(currentString, TOKENS::TOKEN_ADD, this -> lineNumber);
        if(currentString == "-")
        return Token(currentString, TOKENS::TOKEN_MINUS, this -> lineNumber);
        if(currentString == "*")
        return Token(currentString, TOKENS::TOKEN_MUL, this -> lineNumber);
        if(currentString == "/")
        return Token(currentString, TOKENS::TOKEN_DIV, this -> lineNumber);
        if(currentString == "=")
        return Token(currentString, TOKENS::TOKEN_EQUALS, this -> lineNumber);
        if(currentString == ";")
        return Token(currentString, TOKENS::TOKEN_SEMICOLON, this -> lineNumber);
        if(currentString == "{")
        return Token(currentString, TOKENS::TOKEN_LFBRACKET, this -> lineNumber);
        if(currentString == "}")
        return Token(currentString, TOKENS::TOKEN_RFBRACKET, this -> lineNumber);
        if(currentString == "(")
        return Token(currentString, TOKENS::TOKEN_LPAREN, this -> lineNumber);
        if(currentString == ")")
        return Token(currentString, TOKENS::TOKEN_RPAREN, this -> lineNumber);
        if(currentString == "<")
        return Token(currentString, TOKENS::TOKEN_LABRACKET, this -> lineNumber);
        if(currentString == ">")
        return Token(currentString, TOKENS::TOKEN_RABRACKET, this -> lineNumber);
        if(currentString == "#")
        return Token(currentString, TOKENS::TOKEN_HASH, this -> lineNumber);
        if(currentString == ";")
        return Token(currentString, TOKENS::TOKEN_SEMICOLON, this -> lineNumber);
        throw "Invalid Input String";
    }
    else if(TypeChecker::isStringADataType(currentString))
    {
        if(currentString == "int")
        return Token(currentString, TOKEN_INTDATATYPE, this -> lineNumber);
        if(currentString == "char")
        return Token(currentString, TOKEN_CHARDATATYPE, this -> lineNumber);
        if(currentString == "double")
        return Token(currentString, TOKEN_DOUBLEDATATYPE, this -> lineNumber);
        if(currentString == "string")
        return Token(currentString, TOKEN_STRINGDATATYPE, this -> lineNumber);
        throw "invalid data Type";
    }
    return Token(currentString, TOKENS::TOKEN_IDENTIFIER, this -> lineNumber);
}

void Lexer::lexTokens()
{
    std::string currentString;
    while(this -> currentCharIndex < this -> sourceTextSize)
    {
        skipWhiteSpace();
        Token token = getTokenFromCurrentChar();
        // std::cout << token.getTokenType() << " " << token.getTokenValue() << " " << token.getLineNumber() << std::endl;
        lexedTokens.emplace_back(token);
        skipWhiteSpace();
    }
}

void Lexer::skipWhiteSpace()
{
    while(isspace(this -> currentChar))
    {
        if(this -> currentChar == '\n')
        {
            this -> lineNumber += 1;
        }
        if(!advanceLexer())
        break;
    }
}

void Lexer::printLexedTokens()
{
    for(int i = 0; i < (int16_t)this -> lexedTokens.size(); i += 1)
    {
        this -> lexedTokens[i].printToken();
    }
}

std::vector <Token> Lexer::getLexedTokens()
{
    return this -> lexedTokens;
}