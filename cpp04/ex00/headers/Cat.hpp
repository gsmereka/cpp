#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "../headers/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string& name);
		~Cat();
		Cat& operator=(const Cat &other);
		Cat(const Cat &other);
		void makeSound() const;
};

#endif
