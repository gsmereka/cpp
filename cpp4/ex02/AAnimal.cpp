/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:40:38 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:40:40 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Aanimal") {
	std::cout << "AAnimal Default Constructor called 👻" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called 👻☠️" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "AAnimal Copy Constructor called 👻👻" << std::endl;
	*this = src;
}

AAnimal&	AAnimal::operator=(AAnimal const &src) {
	std::cout << "AAnimal copy assignment operator called 👻=👻" << std::endl;
	this->type = src.getType();
	return *this;
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal Constructor called with type: " << type << std::endl;
	this->setType(type);
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

std::string	AAnimal::getType(void) const {
	return this->type;
}

// void	AAnimal::makeSound(void) const {
// 	std::cout << "* generic sound *" << std::endl;
// }