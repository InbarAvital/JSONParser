#include "numberType.h"


int getLastDigit(std::string str) {
    unsigned int counter = 0;
    while (counter < str.length()) {
        if (!isdigit(str[counter])) {
            return counter;
        }
        counter++;
    }
    return counter;
}

bool NumberType::isType(std::string str) {
    int len = getEnd(str);
    if (len == str.length()) {
        return true;
    }
    return false;
}

int calcFraction(std::string str) {
    int frc_len, str_len = str.length();
    if (!(str[0] == '.')) {
        return calcExponent(str);
    } else {
        frc_len = 1 + getLastDigit(str.substr(1, str_len - 1));
    }
    int exponent_res = calcExponent(str.substr(frc_len, str_len - frc_len));
    if (exponent_res == 0) {
        return 0;
    }
    return frc_len + exponent_res;
}

int calcExponent(std::string str) {
    int counter = 1;
    if (str[0] != 'e' && str[0] != 'E') {
        return 0;
    }
    if (str[1] == '-' || str[1] == '+') {
        counter++;
    }
    int lastdig = getLastDigit(str.substr(counter, str.length() - counter));
    if(lastdig == 0) {
        return 0;
    }
    return counter + lastdig;
}


int NumberType::getEnd(std::string str) {
    int counter = 0, str_len = str.length();
    if (str[counter] == '-') {
        counter++;
    }
    if (str[counter] == '0') {
        counter++;
    }
    else if (isdigit(str[counter])) {
        counter += getLastDigit(str.substr(counter, str_len - counter));
    }
    else {
        return 0;
    }
    int frac_res = calcFraction(str.substr(counter, str_len - counter));
    return counter + frac_res;
}

bool NumberType::isPartialType(std::string str) {
    return true;
}