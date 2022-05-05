#include <iostream>
#include "whitespaceType.h"
#include "numberType.h"

int main() {
    WhitespaceType type("\n");
    std::cout << type.getContents();
    std::cout << type.getName() << std::endl;
    std::cout << NumberType::getEnd("-.3s");
}