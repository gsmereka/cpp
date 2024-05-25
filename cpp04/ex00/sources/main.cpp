#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include <iostream>



int main()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Creating Animal" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    const Animal        *animal = new Animal();
    std::cout << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << "Creating Dog and Cat" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    const Animal        *dog = new Dog();
    const Animal        *cat = new Cat();
    std::cout << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << "Creating WrongCat" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    const WrongAnimal   *wrongCat = new WrongCat();
    std::cout << std::endl;   

    std::cout << "------------------------------" << std::endl;
    std::cout << "Testing Types" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "type of dog = " << dog->getType() << " " << std::endl;
    std::cout << "type of cat = " << cat->getType() << " " << std::endl;
    std::cout << "type of animal = " << animal->getType() << " " << std::endl;
    std::cout << "type of wrongcat = " << wrongCat->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << "Testing Sounds" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    wrongCat->makeSound();
    std::cout << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << "Cleaning" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongCat;
    
    return 0;
}
