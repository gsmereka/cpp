/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:41:14 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:41:16 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called 🧠" << std::endl;
	std::stringstream ss;
	std::string s;

	for (int i = 0; i < 100; i++) {
		ss << i + 1;
		ss >> s;
		ss.clear();
		this->ideas[i] = "💡 Idea: " + s;
	}
}

Brain::~Brain(void) {
 	std::cout << "Brain destructor called 🧠☠️" << std::endl;
}


Brain::Brain(const Brain & src) {
	std::cout << "Brain copy constructor called 🧠🧠" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Brain assignment operator called 🧠=🧠" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.getIdea(i);
	}
	return (*this);
}

std::string Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}
