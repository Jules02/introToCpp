//
// Created by Jules Dupont on 24/09/2024.
//

#include <iostream>
#include <ostream>

float arrayAverage(const int array[], int size);

int fibonacci(int n);

int main() {

    int MyArray[5] = {3, 6, 7, 90, 100};
    float avg_MyArray = arrayAverage(MyArray, 5);
    std::cout << avg_MyArray << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << fibonacci(i) << std::endl;
    }

    return 0;
}

float arrayAverage(const int array[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (float) array[i];
    }
    float avg = sum / (float) size;
    return avg;
}

int fibonacci(int n) {
    int fib0 = 0;
    if (n == 0) { return fib0; }
    int fib1 = 1;
    if (n == 1) { return fib1; }

    int fib_n_moinsUn = fib0;
    int fib_n = fib1;

    for (int i = 2; i <= n; ++i) {
        const int tmp = fib_n;
        fib_n = fib_n_moinsUn + fib_n;
        fib_n_moinsUn = tmp;
    }
    return fib_n;
}