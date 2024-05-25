#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <string>
# include "../headers/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string& name);
		~WrongCat();
		WrongCat& operator=(const WrongCat &other);
		WrongCat(const WrongCat &other);
		void makeSound() const;
};

#endif
