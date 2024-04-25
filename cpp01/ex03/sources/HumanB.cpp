#include "../headers/HumanB.hpp"

HumanB::HumanB(void)
{
	return;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " died..." << std::endl;
	return;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void    HumanB::attack(void)
{
    std::cout << this->name << "attacks with their" << weapon->getType() << std::endl;

}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}