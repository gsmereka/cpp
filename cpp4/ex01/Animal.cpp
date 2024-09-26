/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:40:18 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:40:20 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("animal") {
	std::cout << "Animal Default Constructor called 🐻" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called 🐻☠️" << std::endl;
}

Animal::Animal(Animal const &src) {
	std::cout << "Animal Copy Constructor called 🐻🐻" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(Animal const &src) {
	std::cout << "Animal copy assignment operator called 🐻=🐻" << std::endl;
	this->type = src.getType();
	return *this;
}

Animal::Animal(std::string type) {
	std::cout << "Animal Constructor called with type: " << type << std::endl;
	this->setType(type);
}

void Animal::setType(std::string type) {
	this->type = type;
}

std::string	Animal::getType(void) const {
	return this->type;
}

void	Animal::makeSound(void) const {
	std::cout << "* generic sound 🐻🎵 *" << std::endl;
}
