#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string& name);
		~Cat();
		Cat& operator=(const Cat &other);
		Cat(const Cat &other);
		void makeSound() const;
	private:
		Brain *brain;
};

#endif
