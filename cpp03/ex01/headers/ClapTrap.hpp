#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap(const std::string& name);
		ClapTrap();
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap &other);
		ClapTrap(const ClapTrap &other);
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Getters
		std::string getName() const;
		int 		getHitPoints() const;
		int 		getEnergyPoints() const;
		int 		getAttackDamage() const;

		// extra
		void		showStatus();
	protected:
		std::string name;
		int         hitPoints;
		int			energyPoints;
		int			attackDamage;
};

#endif
