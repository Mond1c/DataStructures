//
// Created by Mihail Kornilovich on 19.11.2021.
//
#include "Vector.h"

int main() {
    Vector<int> vec{};
    vec.pushBack(1);
    vec.pushBack(2);
    std::cout << vec << std::endl;
    return 0;
}
