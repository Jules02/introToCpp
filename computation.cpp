//
// Created by Jules Dupont on 24/09/2024.
//

#include <iostream>
#include <ostream>

int arrayAverage(int array[], int size);

int main() {

    int MyArray[5] = {3, 6, 7, 90, 100};

    int avg_MyArray = arrayAverage(MyArray, 5);

    std::cout << avg_MyArray << std::endl;

    return 0;
}

int arrayAverage(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}