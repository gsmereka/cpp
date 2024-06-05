#include "../headers/EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) 
{
	std::cout << "\n-----------------------------------" << std::endl;
	std::cout << "TEST VECTOR" << std::endl;
	std::cout << "-----------------------------------\n" << std::endl;
	try
	{
		std::vector<int> vec(5, 42);
		std::vector<int>::iterator	valueFind;

		std::cout << "Trying to find 42" << std::endl;
		valueFind = ::easyFind(vec, 42);
		std::cout << "Value find: " << *valueFind << std::endl;

		std::cout << "Trying to find 5" << std::endl;
		valueFind = ::easyFind(vec, 5);
		std::cout << "Value find: " << *valueFind << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------" << std::endl;
	std::cout << "TEST LIST" << std::endl;
	std::cout << "-----------------------------------\n" << std::endl;

	try
	{
		std::list<int>				lst;
		std::list<int>::iterator	valueFind;

		lst.push_back(4);
		lst.push_back(42);
		lst.push_back(2);
		std::cout << "Trying to find 42" << std::endl;
		valueFind = ::easyFind(lst, 42);
		std::cout << "Value find: " << *valueFind << std::endl;

		std::cout << "Trying to find 1" << std::endl;
		valueFind = ::easyFind(lst, 1);
		std::cout << "Value find: " << *valueFind << std::endl;;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------" << std::endl;
	std::cout << "TEST DEQUE" << std::endl;
	std::cout << "-----------------------------------\n" << std::endl;

	try
	{
		std::deque<int> deque(5);
        deque[0] = 5;
        deque[1] = 2;
        deque[2] = 3;
        deque[3] = 8;
        deque[4] = 12;
		deque.push_back(42);

		std::deque<int>::iterator valueFind;

		std::cout << "Trying to find 42" << std::endl;
		valueFind = easyFind(deque, 42);
		std::cout << "Value find: " << *valueFind << std::endl;

		std::cout << "Trying to find 10" << std::endl;
		valueFind = easyFind(deque, 10);
		std::cout << "Value find: " << *valueFind << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}