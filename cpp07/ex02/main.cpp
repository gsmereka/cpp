#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Test default constructor" << std::endl;
    std::cout << "------------------------------" << std::endl;

    {
        Array<int> arr;
        std::cout << "Size of default array: " << arr.size() << std::endl;

        try {
            std::cout << "Accessing element at index 0: " << arr[0] << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Test parameterized constructor" << std::endl;
    std::cout << "------------------------------" << std::endl;

    {
        Array<int> arr(5);
        std::cout << "Size of array with 5 elements: " << arr.size() << std::endl;
        try {
            std::cout << "Accessing element at index 3: " << arr[3] << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Test copy constructor" << std::endl;
    std::cout << "------------------------------" << std::endl;

    {
        Array<int> arr1(3);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;

        std::cout << "Elements of arr1: ";
        for (size_t i = 0; i < arr1.size(); ++i)
        {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr2(arr1);
        std::cout << "Size of arr2 (copied from arr1): " << arr2.size() << std::endl;
        std::cout << "Elements of arr2: ";
        for (size_t i = 0; i < arr2.size(); ++i)
        {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Modify arr1" << std::endl;
        arr1[1] = 20;

        std::cout << "Elements of arr2 after modifying arr1: ";
        for (size_t i = 0; i < arr2.size(); ++i)
        {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Elements of arr1 after modifying arr1: ";
        for (size_t i = 0; i < arr1.size(); ++i)
        {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Test assignment operator" << std::endl;
    std::cout << "------------------------------" << std::endl;

    {
        Array<int> arr1(4);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr1[3] = 4;

        std::cout << "Elements of arr1: ";
        for (size_t i = 0; i < arr1.size(); ++i)
        {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr2;
        arr2 = arr1;

        std::cout << "Size of arr2 (assigned from arr1): " << arr2.size() << std::endl;
        std::cout << "Elements of arr2: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Modify arr1" << std::endl;
        arr1[2] = 30;

        std::cout << "Elements of arr2 after modifying arr1: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Elements of arr1 after modifying arr1: ";
        for (size_t i = 0; i < arr1.size(); ++i)
        {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Test out-of-bounds exception" << std::endl;
    std::cout << "------------------------------" << std::endl;

    {
        Array<int> arr(2);
        try
        {
            std::cout << "Trying to access element at index 5: " << arr[5] << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}
