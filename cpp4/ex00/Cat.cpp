/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:37:54 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:37:56 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Cat Default Constructor called 🐈" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called 🐈☠️" << std::endl;
}

Cat::Cat(Cat const &src): Animal("Cat") {
	std::cout << "Cat Copy Constructor called 🐈 🐈" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &src) {
    this->type = src.getType();
	std::cout << "Cat copy assignment operator called 🐈=🐈" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* Miau rrrrrrr miau 🐈 🎵 *" << std::endl;
}
