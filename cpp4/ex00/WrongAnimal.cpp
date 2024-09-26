/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:36:23 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/25 23:07:19 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal") {
	std::cout << "WrongAnimal Default Constructor called 🕷🕸" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called 🕷🕸" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src): type(src.type) {
	std::cout << "WrongAnimal Copy Constructor called 🕷🕷🕸" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout << "WrongAnimal copy assignment operator called 🕷=🕷🕸" << std::endl;
	this->type = src.getType();
	return *this;
}

WrongAnimal::WrongAnimal(std::string const type) {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
	this->setType(type);
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType(void) const {
    return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "* WrongAnimal sound 🕷🎵 *" << std::endl;
}
