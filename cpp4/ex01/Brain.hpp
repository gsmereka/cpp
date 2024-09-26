/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:39:34 by mmaidel-          #+#    #+#             */
/*   Updated: 2024/09/23 22:39:35 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain {

public:
    Brain(void);
    ~Brain(void);

    Brain(const Brain &src);
    Brain &operator=(const Brain &src);

    void setIdea(int i, std::string idea);
    std::string getIdea(int i) const;

private:
    std::string ideas[100];
};

#endif
