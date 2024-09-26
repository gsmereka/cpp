/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:39:19 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:39:21 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:

    Cat(void);
    ~Cat(void);
    Cat(Cat const &src);
    Cat& operator=(Cat const &src);

    void makeSound(void) const;
    Brain *getBrain(void) const;

private:

    Brain* brain;
};

#endif
