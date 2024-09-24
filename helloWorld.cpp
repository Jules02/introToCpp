//
// Created by Jules Dupont on 24/09/2024.
//

#include "helloWorld.h"

#include <iostream>

void printGreetings(int upperBound);

int main() {
    printGreetings(10);
    return 0;
}

void printGreetings(int upperBound) {
    for (int i = 2; i <= upperBound; i+=2) {
        std::cout << i << std::endl;
    }
    std::cout << "Hello World!\n";
    for (int i = upperBound + (upperBound % 2 - 1); i >= 1; i-=2) {
        std::cout << i << std::endl;
    }
}
