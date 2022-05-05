#include "whitespaceType.h"

bool WhitespaceType::isType(std::string str) {
    // checking length
    if (str.length() != 1) {
        return false;
    }
    // checking if it is a whitespace
    return isPartialType(str);
}

int WhitespaceType::getEnd(std::string str) {
    if (isType(str)) {
        return 1;
    } else {
        return -1;
    }
}

bool WhitespaceType::isPartialType(std::string str) {
    int i;
    // checking if it is a whitespace
    char c = str[0];
    char whitespaces[WHITESPACES_AMOUNT] = { ' ', '\n', '\t', '\r' };
    for (i = 0; i < WHITESPACES_AMOUNT; i++) {
        if (whitespaces[i] == c) {
            return true;
        }
    }
    return false;
}
