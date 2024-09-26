/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:37:47 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:37:50 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

public:

    Cat(void);
    ~Cat(void);
    Cat(Cat const &src);
    Cat& operator=(Cat const &src);

    void makeSound(void) const;

};

#endif
