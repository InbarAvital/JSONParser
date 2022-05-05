#ifndef WHITESPACE_TYPE_H
#define WHITESPACE_TYPE_H

#include "jsonType.h"

#define WHITESPACES_AMOUNT 4

class WhitespaceType : public JsonType {
public:
    WhitespaceType(std::string value) : JsonType { "whitespace", value } {}
    ~WhitespaceType(){}
    static bool isType(std::string str);
    static int getEnd(std::string str);
    static bool isPartialType(std::string str);
};
#endif // WHITESPACE_TYPE_H