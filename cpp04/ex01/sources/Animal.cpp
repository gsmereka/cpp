#include "../headers/Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal " << " created!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << " destroyed!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->operator=(other);
}

Animal &Animal::operator = (const Animal &obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Default Sound" << std::endl;
}