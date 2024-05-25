#include "../headers/Cat.hpp"
#include <iostream>

Cat::Cat() 
	: Animal()
{
	brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat Default Constructor!" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor!" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other)
{
	this->type = "Cat";
	brain = new Brain(*other.brain);
	std::cout << "Cat Copy Constructor!" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "Cat Copy Assignment Operator!" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miau" << std::endl;
}