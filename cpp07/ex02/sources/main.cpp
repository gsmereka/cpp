#include <iostream>
#include "../headers/Array.hpp"

#include <iostream>
#include <cstdlib>
// #include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main2() {
    try {
        // Test default constructor
        Array<int> defaultArray;
        std::cout << "Default array size: " << defaultArray.size() << std::endl;

        // Test constructor with size
        unsigned int size = 5;
        Array<int> sizedArray(size);
        std::cout << "Sized array size: " << sizedArray.size() << std::endl;

        // Test subscript operator and initialization
        for (unsigned int i = 0; i < size; ++i) {
            sizedArray[i] = i + 1;
        }
        std::cout << "Sized array elements: ";
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << sizedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copiedArray(sizedArray);
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Copied array elements: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test assignment operator
        Array<int> assignedArray;
        assignedArray = sizedArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "Assigned array elements: ";
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << assignedArray[size] << std::endl; // Should throw exception
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}