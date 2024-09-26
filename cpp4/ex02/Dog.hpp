/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:40:51 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:40:52 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

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
