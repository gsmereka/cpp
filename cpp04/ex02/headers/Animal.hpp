#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal& operator=(const Animal &other);
		Animal(const Animal &other);

		std::string getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string	type;
};

#endif
