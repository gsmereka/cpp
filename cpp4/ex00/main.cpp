/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:37:12 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/25 23:10:05 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Test Polymorphism Class - Animal Class has a virtual method makeSound" << std::endl << std::endl;
    const Animal* meta = new Animal();
    std::cout << " Animal class (base) receives a Dog class (derived)" << std::endl;
    const Animal* j = new Dog();
    std::cout << " Animal class (base) receives a Cat class (derived)" << std::endl;
    const Animal* i = new Cat();

    std::cout << std::string(80, '-') << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    std::cout << j->getType() << " " << std::endl;
    std::cout << "j->makeSound(): Dog class makeSound is called through a base class pointer" << std::endl << std::endl;
    j->makeSound();
    std::cout << "i->makeSound(): Cat class makeSound is called through a base class pointer" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << std::endl;
    
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "WrongAnimal Class DOES NOT HAVE a virtual method makeSound" << std::endl;

    const WrongAnimal* test = new WrongAnimal();
    const WrongAnimal* test2 = new WrongCat(); 

    std::cout << std::endl;
    
    std::cout << test->getType() << std::endl;
    test->makeSound();
    std::cout << test2->getType() << std::endl;
    std::cout << "test2->makeSound(); WrongCat class makeSound is called through a base class pointer" << std::endl;

    test2->makeSound();

    std::cout << std::string(80, '-') << std::endl;

    delete i;
    delete j;
    delete meta;
    delete test;
    delete test2;

    return 0;
}