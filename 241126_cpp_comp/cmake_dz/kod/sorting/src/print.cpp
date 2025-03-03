#include "print.hpp"

#include <iostream>

void eshkere::print(const char* const comment, int* arr, const int size) {
    const char format = ' ';
    std::cout << comment;
    for (int i = 0; i < size; i++){
        std::cout << format << arr[i];
    }
    std::cout << std::endl;
}