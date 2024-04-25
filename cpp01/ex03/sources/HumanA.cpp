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

HumanA::HumanA(std::string name)
{
	this->name = name;
}


void	HumanA::setName(std::string name)
{
	this->name = name;
}