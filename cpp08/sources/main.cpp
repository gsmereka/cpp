#include "../headers/EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) 
{
    std::cout << "\n-----------------------------------" << std::endl;
    std::cout << "TEST VECTOR" << std::endl;
    std::cout << "-----------------------------------\n" << std::endl;
	try
    {
		std::vector<int> vec(5, 1);
		std::vector<int>::iterator	valueFind;

        std::cout << "Trying to find 1" << std::endl;
		valueFind = ::easyFind(vec, 1);
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

		lst.push_back(10);
		lst.push_back(44);
		lst.push_back(30);
        std::cout << "Trying to find 44" << std::endl;
		valueFind = ::easyFind(lst, 44);
		std::cout << "Value find: " << *valueFind << std::endl;

        std::cout << "Trying to find 1" << std::endl;
		valueFind = ::easyFind(lst, 1);
		std::cout << "Value find: " << *valueFind << std::endl;;
	}
	catch (const std::exception& e)
    {
		std::cout << "Error: " << e.what() << std::endl;
	}
}