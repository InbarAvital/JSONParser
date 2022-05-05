#ifndef VALUE_TYPE_H
#define VALUE_TYPE_H

#include "jsonType.h"

class ValueType : public JsonType {
public:
    ValueType(std::string value) : JsonType { "value", value } {}
    ~ValueType(){}
    static bool isType(std::string str);
    static int getEnd(std::string str);
    static bool isPartialType(std::string str);
};
#endif // VALUE_TYPE_H