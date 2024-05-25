#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include "../headers/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap& operator=(const FragTrap &other);

		void attack(const std::string& target);

		// extra
		void highFivesGuys();
};

#endif
