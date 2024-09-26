/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:41:19 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:41:22 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

# include <string>
# include <iostream>


class AAnimal {

public:

    AAnimal(void);
    virtual ~AAnimal(void); // É o destrutor virtual da classe AAnimal. Ele é declarado como virtual para permitir a 
    // destruição correta dos objetos de subclasses quando eles são manipulados por meio de ponteiros para a 
    // classe base.
    AAnimal(AAnimal const &src);
    AAnimal&	operator=(AAnimal const &src);

    AAnimal(std::string type);
    
    void setType(std::string type);
    std::string	getType(void) const;

    virtual void	makeSound(void) const = 0; //  É um método virtual puro da classe AAnimal, ele precisa ser 
    // implementado nas subclasses. Esse método é responsável por produzir o som característico do animal.

protected:

    std::string	type;

};

#endif
