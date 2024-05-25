#include "../headers/Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain created!" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
    std::cout << "Brain copied!" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Assignation with operator= called" <<std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
