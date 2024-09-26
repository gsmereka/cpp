/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:36:18 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/25 23:08:17 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {

public:

    WrongAnimal(void);
        ~WrongAnimal(void); // not virtual, so not polymorphic
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal & operator=(WrongAnimal const &src);
    
        WrongAnimal(std::string type);
    
        void setType(std::string type);
        std::string	getType(void) const;
        void	makeSound(void) const; // not virtual, so not polymorphic
protected:

    std::string	type;
};

#endif
