#include "../headers/HumanA.hpp"

HumanA::HumanA(void)
{
	return;
}

HumanA::~HumanA(void)
{
	std::cout << this->name << " died..." << std::endl;
	return;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
    this->weapon = &weapon;
}

void    HumanA::attack(void)
{
    std::cout << this->name << "attacks with their" << weapon->getType() << std::endl;

}
