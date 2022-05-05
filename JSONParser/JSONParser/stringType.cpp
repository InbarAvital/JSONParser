#include "stringType.h"

bool isAllowedChar(char c) {
    int i;
    char allowed[ALLOWED_CHARS_AMOUNT] = { '\"', '\\', '/', 'b', 'f', 'n', 'r', 't', 'u' };
    for(i = 0 ; i < ALLOWED_CHARS_AMOUNT ; i++) {
        if (c == allowed[i]) {
            return true;
        }
    }
    return false;
}

bool isHexNumber(std::string str) {
    int i, j;
    char allowed[HEX_DIGITS_AMOUNT] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', \
                                        '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    if (str.length() < HEX_SIZE) {
        return false;
    }
    for (j = 0 ; j <HEX_SIZE ; j++) {
        for (i = 0 ; i < HEX_DIGITS_AMOUNT ; i++) {
            if (str[j] == allowed[i]) {
                return true;
            }
        }
    }
    return false;
}

static bool isType(std::string str) {
    unsigned int i;
    if (str[0] != '\"' || str[str.length() - 1] != '\"') {
        return false;
    }
    std::string str_con = str.substr(1, str.length() - 2);
    for (i = 0 ; i < str_con.length() ; i++) {
        if (str_con[i] == '\"') {
            return false;
        }
        if (str_con[i] == '\\') {
            if (!isAllowedChar(str_con[i + 1]) || i == str_con.length() - 1) {
                return false;
            }
            if (str_con[i + 1] == 'u') {
                if (!isHexNumber(str_con.substr(i + 2, str_con.length() - i - 2))) {
                    return false;
                }
                i+=HEX_SIZE;
            }
            i++;
        }
    }
}

static int getEnd(std::string str) {
    unsigned int i;
    for (i = 1 ; i < str.length() ; i++) {
        if (str[i] == '\"' && str[i - 1] == '\\') {
            return i + 1;
        }
    }
    return -1;
}

static bool isPartialType(std::string str) {
    if (str[0] == '\"' && getEnd(str) != -1) {
        return true;
    }
    return false;
}