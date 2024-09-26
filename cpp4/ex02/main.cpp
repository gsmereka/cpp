/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:40:46 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:40:47 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
    
int main()
{
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Test subject -- AAnimal Abstract Class" << std::endl;
	std::cout << std::string(80, '-') << std::endl;

	//const AAnimal* meta = new AAnimal();  // object of abstract class type "AAnimal" is not allowed: -- function "AAnimal::makeSound" is a pure virtual function
	const AAnimal* d = new Dog();
	const AAnimal* c = new Cat();

	std::cout << std::string(80, '-') << std::endl;

	// std::cout << meta->getType() << " " << std::endl;
	// meta->makeSound();
	std::cout << d->getType() << " " << std::endl;
	d->makeSound();
	std::cout << c->getType() << " " << std::endl;
    c->makeSound();

	std::cout << std::string(80, '-') << std::endl;

	delete d;
	delete c;
	//delete meta;
	
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "Test Brain" << std::endl;
		std::cout << std::string(80, '-') << std::endl;
		std::string	ideas[100] = { "Hi, ", "I'm", "a", "thinking", "Brain"};

		Brain	a;

		std::cout << std::endl;
		std::cout << "Filling a with ideas (deep copy)" << std::endl;
		for(int i = 0; i < 5; i++)
			a.setIdea(i, ideas[i]);
		
		Brain	b(a);
		std::cout << std::endl;
		
		std::cout << "🧠 Brain a: ";
		for(int i = 0; i < 5; i++)
			std::cout << a.getIdea(i) << " ";
		std::cout << std::endl;
		
		std::cout << "🧠 Brain b: ";
		for(int i = 0; i < 5; i++)
			std::cout << b.getIdea(i) << " ";
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "Changing an idea in b......" << std::endl;
		std::string	ideas2[100] = { "I", "changed", "all", "my", "ideas"};
		for(int i = 0; i < 5; i++)
			b.setIdea(i, ideas2[i]);
			
		std::cout << std::endl;
		std::cout << "🧠 Brain a: ";
		for(int i = 0; i < 5; i++)
			std::cout << a.getIdea(i) << " ";
		std::cout << std::endl;
		
		std::cout << "🧠 Brain b: ";
		for(int i = 0; i < 5; i++)
			std::cout << b.getIdea(i) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "Test Animal - Cat and Dog - with brains" << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		AAnimal*	animal;
		Cat*	cat = new Cat();
		Dog*	dog = new Dog();

		std::string	ideas[100] = {"A", "B", "C"};
		std::string	dogIdeas[100] = {"play", "ball", "run", "eat", "play", "sleep", "play"};

		// set Cat ideias
		for(int i = 0; i < 3; i++)
			cat->getBrain()->setIdea(i, ideas[i]);
		std::cout << std::endl;

		std::cout << "🐈 Cat's ideas: ";
		for(int i = 0; i < 3; i++)
			std::cout << cat->getBrain()->getIdea(i) << " ";
		std::cout << std::endl;
		
		// set Dog ideias
		for(int i = 0; i < 7; i++)
			dog->getBrain()->setIdea(i, dogIdeas[i]);

		std::cout << "🐶 Dog's ideas: ";
		for(int i = 0; i < 7; i++)
			std::cout << dog->getBrain()->getIdea(i) << " ";
		std::cout << std::endl;

		std::cout << std::endl;
		
		animal = cat; // the complilator allows to copy the cat in the animal
		//cat = animal; // but does NOT allow to copy the cat in the animal
		// cat = dog; // and also does NOT allow to copy the dog in the cat

		delete animal;
		delete dog;

		std::cout << std::string(80, '-') << std::endl;
	}

}
