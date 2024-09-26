/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:41:04 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:41:05 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Estava inicializando assim, mas o pdf diz: "Após a construção, Cão e Gato criarão seu Cérebro usando new Brain()"
// Cat::Cat(void): Animal("Cat"), brain(new Brain()) {
// 	std::cout << "Cat Default Constructor called" << std::endl;
// }

Cat::Cat(void): AAnimal("Cat") {
	std::cout << "Cat Default Constructor called 🐈" << std::endl;
	this->brain = new Brain(); // assim primeiro aparece o log da construcão do cat e depois do brain
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called 🐈☠️" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &src): AAnimal("Cat") {
	std::cout << "Cat Copy Constructor called 🐈 🐈" << std::endl;
	this->brain = new Brain(*src.getBrain());
    *this = src;
}

Cat &Cat::operator=(Cat const &src) {
    this->type = src.getType();
	*this->brain = *src.getBrain();
	std::cout << "Cat copy assignment operator called 🐈=🐈" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* Miau rrrrrrr miau 🐈 🎵 *" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return this->brain;
}
