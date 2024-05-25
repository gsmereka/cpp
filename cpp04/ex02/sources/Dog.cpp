#include "../headers/Dog.hpp"
#include <iostream>

Dog::Dog() 
	: Animal()
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "Dog Default Constructor!" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor!" << std::endl;
}

Dog::Dog(const Dog &other)
	: Animal(other)
{
	this->type = "Dog";
	brain = new Brain(*other.brain);
	std::cout << "Dog Copy Constructor!" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "Dog Copy Assignment Operator!" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Au Au" << std::endl;
}