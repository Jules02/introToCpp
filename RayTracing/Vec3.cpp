//
// Created by Jules Dupont on 01/10/2024.
//

#include "Vec3.h"
#include <iostream>

int main() {
    Vec3 myVector{10,20,30};
    Vec3 myVector2 = myVector + myVector;
    std::cout << myVector2 << std::endl;

    Vec3 myVector3 = 0.1 * myVector2;
    std::cout << myVector3 << std::endl;
    return 0;
}

