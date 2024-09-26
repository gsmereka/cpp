/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:38:01 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/25 23:06:10 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>
# include <iostream>


class Animal {

public:

    Animal(void);
    virtual ~Animal(void);

    Animal(Animal const &src);
    Animal&	operator=(Animal const &src);

    Animal(std::string type);
    
    void setType(std::string type);
    std::string	getType(void) const;

    virtual void	makeSound(void) const;

protected:

    std::string	type;

};

#endif
