#ifndef ARRAY_TYPE_H
#define ARRAY_TYPE_H

#include "jsonType.h"

class ArrayType : public JsonType {
public:
    ArrayType(std::string value) : JsonType { "array", value } {}
    ~ArrayType(){}
    static bool isType(std::string str);
    static int getEnd(std::string str);
    static bool isPartialType(std::string str);
};
#endif // ARRAY_TYPE_H