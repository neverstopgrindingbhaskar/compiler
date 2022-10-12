#include "parseTree.h"
#include <iostream>
parseTree::parseTree(const std::vector <Token> &token)
{
    this -> tokens = token;
    this -> tokenIndex = 0;
    this -> tokenCount = token.size();
}

bool parseTree::incrementTokenCount()
{
    if(this -> tokenIndex < this -> tokenCount)
    {
        this -> tokenIndex += 1;
        return true;
    }
    return false;
}
bool parseTree::tokenEat(const TOKENS type)
{
    if(getCurrentTokenType() == type)
    {
        return this -> incrementTokenCount();
    }
    else 
    {
        throw "Error while parsing the tree";
    }
}
TOKENS parseTree::getCurrentTokenType()
{
    if(this -> tokenIndex >= this -> tokenCount)
    return TOKENS::TOKEN_NULL;
    return this -> tokens[this -> tokenIndex].getTokenType();
}

std::string parseTree::getCurrentTokenValue()
{
    if(this -> tokenIndex >= this -> tokenCount)
    return "";
    return this -> tokens[this -> tokenIndex].getTokenValue();
}

void parseTree::printTree() 
{

}

integerNode *parseTree::createIntegerNode(const std::string &intValue)
{
    integerNode *newIntegerNode = new integerNode(stoi(intValue));
    return newIntegerNode;
}

binaryNode *parseTree::buildLHS() 
{
    if(getCurrentTokenType() == TOKEN_LPAREN)
    {
        tokenEat(TOKEN_LPAREN);
        binaryNode *retVal = buildBinaryOperator();
        tokenEat(TOKEN_RPAREN);
        return retVal;
    }
    else if(getCurrentTokenType() == TOKEN_INT)
    {
        integerNode *newIntegerNode = createIntegerNode(getCurrentTokenValue());
        tokenEat(TOKEN_INT);
        return (binaryNode *)(newIntegerNode);
    }
    return NULL;
}
binaryNode *parseTree::buildRHS() 
{
    integerNode *newIntegerNode = createIntegerNode(getCurrentTokenValue());
    tokenEat(TOKEN_INT);
    return (binaryNode *)(newIntegerNode);
}
binaryNode *parseTree::buildBinaryOperator() 
{
    binaryNode *lhs = buildLHS();
    binaryNode *retVal = lhs;
    while(TypeChecker::isStringABinaryOperator(getCurrentTokenValue()))
    {
        std::string currToken = getCurrentTokenValue();
        if(currToken == "+")
        tokenEat(TOKEN_ADD);
        else if(currToken == "-")
        tokenEat(TOKEN_MINUS);
        else if(currToken == "*")
        tokenEat(TOKEN_MUL);
        else if(currToken == "/")
        tokenEat(TOKEN_DIV);
        else 
        throw "Invalid Operator";
        retVal = new binaryNode(currToken, lhs, buildBinaryOperator());
    }
    return retVal;
}
void parseTree::buildTreeFromTokens()
{
    if(getCurrentTokenType() == TOKEN_INT || getCurrentTokenType() == TOKEN_LPAREN)
    {
        binaryNode *node = buildBinaryOperator();
        printf("BUILDING OVER PRINTING NOW\n");
        node -> printNode();
    }
}
