//
// Created by Mihail Kornilovich on 19.11.2021.
//
#include "Vector.h"
#include "Set.h"
#include "Stack.h"


int main() {
    Vector<int> vector;
    vector.pushBack(1);
    vector.pushBack(2);
    vector.pushBack(3);
    std::cout << vector[2] << std::endl;
    std::cout << vector << std::endl;

    return 0;
}
