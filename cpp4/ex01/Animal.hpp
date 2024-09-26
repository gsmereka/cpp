/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:40:10 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:40:13 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>
# include <iostream>


class Animal {

public:

    Animal(void);
    virtual ~Animal(void); // É o destrutor virtual da classe Animal. Ele é declarado como virtual para permitir a 
    // destruição correta dos objetos de subclasses quando eles são manipulados por meio de ponteiros para a 
    // classe base.
    Animal(Animal const &src);
    Animal&	operator=(Animal const &src);

    Animal(std::string type);
    
    void setType(std::string type);
    std::string	getType(void) const;

    virtual void	makeSound(void) const; //  indica que a função makeSound é virtual, ou seja, pode ser substituída
    // em classes derivadas, mas não é uma função abstrata. Ela tem uma implementação padrão e pode ser chamada 
    // diretamente na classe base.

protected:

    std::string	type;

};

#endif
