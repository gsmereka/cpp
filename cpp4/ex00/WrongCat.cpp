/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:36:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:36:12 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor called 🐱🕸" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal(src.type) {
	std::cout << "WrongCat Copy Constructor called 🐱🐱🕸" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called 🐱🕸☠️" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & src) {
	std::cout << "WrongCat copy assignment operator called 🐱=🐱🕸" << std::endl;
	this->type = src.type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "* uaiM uaiM 🎵🐱🕸*" << std::endl;
}
