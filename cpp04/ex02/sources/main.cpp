#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include <iostream>

int test_animalsound(void)
{
	Dog dog;
	Cat cat;

	dog.makeSound();
	cat.makeSound();

	// Animal animal;
	// animal.makeSound();
    return (0);
}

int main()
{
    const int arraySize = 10;
    Animal* animals[arraySize];

    std::cout << "------------------------------" << std::endl;
    std::cout << "Creating half Dog and half Cat objects" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i = 0; i < arraySize / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; ++i)
    {
        animals[i] = new Cat();
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Demonstrating polymorphism and type checking" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << animals[i]->getType() << " ";
        animals[i]->makeSound();
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Testing deep copy" << std::endl;
    std::cout << "------------------------------" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Cleaning up" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i = 0; i < arraySize; ++i)
    {
        delete animals[i];
    }

    return 0;
}