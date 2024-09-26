/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:36:05 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:36:06 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
    WrongCat(void);
    ~WrongCat(void);
    WrongCat(const WrongCat &a);
    WrongCat &operator=(const WrongCat &a);

    void makeSound(void) const;
};

#endif
