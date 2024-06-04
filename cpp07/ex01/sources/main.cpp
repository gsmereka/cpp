#include <iostream>
#include "../headers/iter.hpp"

// Sample function to be used with iter - prints the element
template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

// Sample function to increment an integer element
void increment(int& element) {
    ++element;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    ::iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    ::iter(intArray, intArraySize, increment);

    std::cout << "Modified intArray: ";
    ::iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test with an array of strings
    std::string strArray[] = {"one", "two", "three", "four", "five"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original strArray: ";
    ::iter(strArray, strArraySize, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}