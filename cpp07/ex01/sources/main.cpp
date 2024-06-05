#include <iostream>
#include <cctype>
#include "../headers/iter.hpp"

template <typename T>
void printElement(const T &element)
{
	std::cout << element << " ";
}

void increment(int &element)
{
	++element;
}

void toUppercase(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper(str[i]);
	}
}

void square(double &element)
{
	element = element * element;
}

int main(void)
{
	std::cout << "Test with an array of integers:" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	::iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intArraySize, increment);

	std::cout << "Modified intArray: ";
	::iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n------------------------------------------------------------\n" << std::endl;

	std::cout << "Test with an array of strings:" << std::endl;
	std::string strArray[] = {"one", "two", "three", "four", "five"};
	size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original strArray: ";
	::iter(strArray, strArraySize, printElement<std::string>);
	std::cout << std::endl;

	::iter(strArray, strArraySize, toUppercase);

	std::cout << "Modified strArray: ";
	::iter(strArray, strArraySize, printElement<std::string>);
	std::cout << std::endl;

	std::cout << "\n------------------------------------------------------------\n" << std::endl;

	std::cout << "Test with an array of doubles:" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original doubleArray: ";
	::iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	::iter(doubleArray, doubleArraySize, square);

	std::cout << "Modified doubleArray: ";
	::iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	std::cout << "\n------------------------------------------------------------\n" << std::endl;

	std::cout << "Test with a const array of integers:" << std::endl;
	const int constIntArray[] = {10, 20, 30, 40, 50};
	size_t constIntArraySize = sizeof(constIntArray) / sizeof(constIntArray[0]);

	std::cout << "constIntArray: ";
	::iter(constIntArray, constIntArraySize, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n------------------------------------------------------------\n" << std::endl;

	std::cout << "Test with a const array of strings:" << std::endl;
	const std::string constStrArray[] = {"apple", "banana", "cherry"};
	size_t constStrArraySize = sizeof(constStrArray) / sizeof(constStrArray[0]);

	std::cout << "constStrArray: ";
	::iter(constStrArray, constStrArraySize, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
