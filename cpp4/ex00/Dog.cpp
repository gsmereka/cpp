/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:37:41 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:37:43 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog Default Constructor called 🐶" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called 🐶☠️" << std::endl;
}

Dog::Dog(Dog const &src): Animal("Dog") {
	std::cout << "Dog Copy Constructor called 🐶 🐶" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &src) {
    this->type = src.getType();
	std::cout << "Dog copy assignment operator called 🐶=🐶" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "* Auau rrr auau 🐶 🎵 *" << std::endl;
}
