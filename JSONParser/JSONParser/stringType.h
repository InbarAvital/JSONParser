#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include "jsonType.h"

#define ALLOWED_CHARS_AMOUNT 9
#define HEX_DIGITS_AMOUNT 16
#define HEX_SIZE 4

class StringType : public JsonType {
private: 
    bool isAllowedChar(char c);
    bool isHexNumber(char c);
public:
    StringType(std::string value) : JsonType { "string", value } {}
    ~StringType(){}
    static bool isType(std::string str);
    static int getEnd(std::string str);
    static bool isPartialType(std::string str);
};
#endif // STRING_TYPE_H