#include "../headers/Cat.hpp"
#include <iostream>

Cat::Cat() 
	: Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor!" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other)
{
	this->type = "Cat";
	std::cout << "Cat Copy Constructor!" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat Copy Assignment Operator!" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miau" << std::endl;
}