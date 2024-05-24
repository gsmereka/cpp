#include "../headers/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->type = "ClapTrap";
	std::cout << type << " " << name << " Default Construtor!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << type << " " << name << " Default Destructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Claptrap" << " Copy Constructor!" << std::endl;
	this->operator=(other);
}

ClapTrap &ClapTrap::operator = (const ClapTrap &obj)
{
	std::cout << "Claptrap" << " Copy Assingment Constructor!" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
		this->type = "ClapTrap";
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << type << " " << name << " cannot attack!" << std::endl;
		return ;
	}
	std::cout << type << " " << name << " attacks " << target << ", causing " 
				<< attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << type << " " << name << " is already dead!" << std::endl;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << type << " " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << type << " " << name << " cannot be repaired!" << std::endl;
		return ;
	}
	hitPoints += amount;
	std::cout << type << " " << name << " is repaired by " << amount << " points!" << std::endl;
	energyPoints--;
}

std::string ClapTrap::getName() const
{
	return name;
}

std::string ClapTrap::getType() const
{
	return type;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

// extra

void ClapTrap::showStatus()
{
	std::cout << type << " "<< getName() << " - " << "[HP:" << getHitPoints() << " EP:" << getEnergyPoints() << " AD:" << getAttackDamage() << "]" << std::endl << std::endl;
}
