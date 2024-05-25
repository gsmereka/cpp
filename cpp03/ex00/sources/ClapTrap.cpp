#include "../headers/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	this->name = "C-3PO";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->operator=(other);
}

ClapTrap &ClapTrap::operator = (const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " 
				<< attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
		return ;
	}
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
	energyPoints--;
}

std::string ClapTrap::getName() const
{
	return name;
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
	std::cout << "ClapTrap "<< getName() << " - " << "[HP:" << getHitPoints() << " EP:" << getEnergyPoints() << " AD:" << getAttackDamage() << "]" << std::endl << std::endl;
}
