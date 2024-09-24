//
// Created by Jules Dupont on 24/09/2024.
//

#include "helloWorld.h"

#include <iostream>

int main() {
    for (int i = 2; i <= 10; i+=2) {
        std::cout << i << std::endl;
    }
    std::cout << "Hello World!\n";
    for (int i = 9; i >= 1; i-=2) {
        std::cout << i << std::endl;
    }
    return 0;
}
