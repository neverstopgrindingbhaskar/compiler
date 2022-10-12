#include "Expressions.h"
binaryNode::binaryNode(const std::string &currNodeVal, binaryNode *lptr, binaryNode *rptr) : treeNode(currNodeVal)
{
    this -> leftPtr = lptr;
    this -> rightPtr = rptr;
}
binaryNode::binaryNode(const std::string &currNodeVal) : treeNode(currNodeVal)
{
    this -> leftPtr = NULL;
    this -> rightPtr = NULL;
}
// binaryNode::binaryNode(integerNode ptr) : treeNode(ptr -> getNodeValue())
// {
//     printf("CONSTRUCTOR CALLED\n");
//     this -> leftPtr = NULL;
//     this -> rightPtr = NULL;
// }
integerNode::integerNode(int val) : binaryNode(std::to_string(val))
{
    
}

int integerNode::getIntegerNodeValue()
{
    return std::stoi(this -> getNodeValue());
}

treeNode::treeNode(const std::string &value) 
{
    this -> nodeValue = value;
}

std::string &treeNode::getNodeValue() 
{
    return this -> nodeValue;
}
void binaryNode::printBinaryTree(std::string &result, binaryNode *ptr, std::string padding, std::string pointer)
{
    if(ptr != NULL)
    {
        result += '\n';
        result += padding;
        result += pointer;
        result += ptr -> getNodeValue();
        
        std::string paddingBuilder = padding;
        if(ptr -> rightPtr != NULL)
        {
            paddingBuilder += "│  ";
        }
        else 
        {
            paddingBuilder += "   ";
        }
        std::string paddingForBoth = paddingBuilder;
        std::string pointerForRight = "└──";
        std::string pointerForLeft = (ptr -> rightPtr != NULL) ? "├──" : "└──";
        printBinaryTree(result, ptr -> leftPtr, paddingForBoth, pointerForLeft);
        printBinaryTree(result, ptr -> rightPtr, paddingForBoth, pointerForRight);
    }
}

void binaryNode::printNode() 
{
    std::string result;
    printBinaryTree(result, this, "", "");
    printf("%s\n", result.c_str());
}

void integerNode::printNode() 
{
    printf("Integer Node value = %d\n", this -> getIntegerNodeValue());
    return;
}