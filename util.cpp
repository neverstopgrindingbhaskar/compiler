#include "util.h"

TypeChecker::TypeChecker()
{

}
const std::vector <std::string> TypeChecker::operators = {"+", "-", "*", "/", "=", "{", "}", "(", ")", "<", ">", "#", ";"};
const std::vector <std::string> TypeChecker::binaryOperators = {"+", "-", "*", "/"};
const std::vector <std::string> TypeChecker::dataTypes = {"int", "char", "double", "string"};
template <typename T>
bool TypeChecker::isPresentInVector(const std::vector <T> &array, const T &searchString)
{
    for(int i = 0; i < (int)array.size(); i += 1)
    {
        if(array[i] == searchString)
        {
            return true;
        }
    }
    return false;
}
bool TypeChecker::isStringAnOperator(const std::string &operatorString)
{
    return isPresentInVector(operators, operatorString);
}
bool TypeChecker::isStringADataType(const std::string &dataTypeString)
{
    return isPresentInVector(dataTypes, dataTypeString);
}
bool TypeChecker::isStringABinaryOperator(const std::string &binaryOperator)
{
    return isPresentInVector(binaryOperators, binaryOperator);
}
bool TypeChecker::isStringANumber(const std::string &numberString)
{
    for(int i = 0; i < (int)numberString.size(); i += 1)
    {
        if(!isdigit(numberString[i]))
        {
            return false;
        }
    }
    return true;
}