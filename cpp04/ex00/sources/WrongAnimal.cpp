#include "../headers/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal " << " created!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << " destroyed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->operator=(other);
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default Sound" << std::endl;
}