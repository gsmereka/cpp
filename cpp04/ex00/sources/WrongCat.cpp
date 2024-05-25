#include "../headers/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() 
	: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
	: WrongAnimal(other)
{
	this->type = "WrongCat";
	std::cout << "WrongCat Copy Constructor!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat Copy Assignment Operator!" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miau" << std::endl;
}