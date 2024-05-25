#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <string>
# include "../headers/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &other);
		ScavTrap(const ScavTrap &other);
	
		void attack(const std::string& target);

		// extra
		void	guardGate();
};

#endif
