#include "../headers/ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() 
	: name("C-3PO"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Name Constructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), 
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap Copy Constructor!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap Copy Assignment Operator!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor!" << std::endl;
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
