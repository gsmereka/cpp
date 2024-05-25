#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "../headers/Animal.hpp"
# include "Brain.hpp"
class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& name);
		~Dog();
		Dog& operator=(const Dog &other);
		Dog(const Dog &other);
		void makeSound() const;
	private:
		Brain *brain;
};

#endif
