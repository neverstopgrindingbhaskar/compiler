#pragma once
#include <string>
#include <vector>
class TypeChecker
{
    public:
        static bool isStringANumber(const std::string &numberString);

        static bool isStringAnOperator(const std::string &operatorString);
        static bool isSemiColon(const std::string &colonString);
        TypeChecker();
        static bool isStringADataType(const std::string &dataTypeString);
        static bool isStringABinaryOperator(const std::string &typeString);
    private:
        static const std::vector <std::string> operators;
        static const std::vector <std::string> binaryOperators;
        static const std::vector <std::string> dataTypes;
        template <typename T>
        static bool isPresentInVector(const std::vector <T> &array, const T &searchString);
};