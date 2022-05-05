#ifndef NUMBER_TYPE_H
#define NUMBER_TYPE_H

#include "jsonType.h"

class NumberType : public JsonType {
public:
    NumberType(std::string value) : JsonType { "number", value } {}
    ~NumberType(){}
    static bool isType(std::string str);
    static int getEnd(std::string str);
    static bool isPartialType(std::string str);
};

bool checkFraction(std::string str);
bool checkExponent(std::string str);
int getLastDigit(std::string str);
int calcFraction(std::string str);
int calcExponent(std::string str);
#endif // NUMBER_TYPE_H