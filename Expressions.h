#pragma once
#include <string>
#include <iostream>
class treeNode 
{
    public:
        treeNode(const std::string &str);
        virtual void printNode() = 0;
        virtual std::string &getNodeValue();
    private:
        std::string nodeValue;
};
class binaryNode: public treeNode 
{
    private:
        binaryNode *leftPtr, *rightPtr;
        void printBinaryTree(std::string &res, binaryNode *ptr, std::string padding, std::string pointer);
    public:
        binaryNode(const std::string &currNodeVal, binaryNode *lptr, binaryNode *rptr);
        void printNode();
        binaryNode(const std::string &currNodeVal);
        // binaryNode(integerNode ptr);
};

class integerNode: public binaryNode 
{
    private:

    public:
        integerNode(int val);
        int getIntegerNodeValue();
        void printNode();
};


class Expression: public treeNode
{
    private:

    public:
        void printNode()
        {

        }
};