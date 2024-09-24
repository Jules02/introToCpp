//
// Created by Jules Dupont on 24/09/2024.
//

#include <iostream>
#include <ostream>
#include <__filesystem/directory_iterator.h>

int sumArray(int arr[], int arraySize);

int main() {

    int arraySize = 100000;

    int integersArray[arraySize];
    for(int i = 0; i < arraySize; ++i) {
        integersArray[i] = 2*(i+1);
    }

    auto start_time_point = std::chrono::high_resolution_clock::now();

    int s = sumArray(integersArray, arraySize);

    auto end_time_point = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time = end_time_point - start_time_point;

    std::cout << "Result: " << s << std::endl;
    std::cout << "Done in: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}

int sumArray(int arr[], int arraySize) {
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += arr[i];
    }
    return sum;
}
