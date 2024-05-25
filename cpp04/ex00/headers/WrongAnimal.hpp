#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &other);
		WrongAnimal(const WrongAnimal &other);

		std::string getType() const;
		void makeSound() const;
	protected:
		std::string	type;
};

#endif
