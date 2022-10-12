#include "token.h"
#include <vector>
#include "Expressions.h"
#include "util.h"
#pragma once
class parseTree 
{
    private:
        std::vector <Token> tokens;
        std::vector <treeNode*> children;
        int tokenIndex;
        int tokenCount;
        bool incrementTokenCount();
        bool tokenEat(TOKENS type);
        TOKENS getCurrentTokenType();
        std::string getCurrentTokenValue();
        binaryNode *buildBinaryOperator();
        integerNode *createIntegerNode(const std::string &intValue);
        binaryNode *buildLHS();
        binaryNode *buildRHS();
    public:
        parseTree(const std::vector <Token> &token);
        void buildTreeFromTokens();
        void printTree();
};