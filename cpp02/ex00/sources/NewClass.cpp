#include <iostream>
#include "../headers/NewClass.hpp"

NewClass::NewClass(void)
{
	std::cout << "Constructor" << std::endl;
}

NewClass::~NewClass(void)
{
	std::cout << "Destructor" << std::endl;
}

NewClass::NewClass(const NewClass &obj)
{
	NewClass::operator = (obj);
}

NewClass &NewClass::operator = (const NewClass &obj)
{
	if (this != &obj)
	{
		// this->XXX = obj.XXX();
	}
	return (*this);
}
