#include "../headers/HumanB.hpp"

HumanB::HumanB(void)
{
	this->weapon = NULL;
	return;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " died..." << std::endl;
	return;
}

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

void    HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " do not have a weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}