/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:38:39 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:38:41 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:

    Dog(void);
    ~Dog(void);
    Dog(Dog const &src);
    Dog & operator=(Dog const &src);

    void makeSound(void) const;
    Brain *getBrain(void) const;

private:
	Brain *brain;

};

#endif
