#include "../headers/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
    : ClapTrap("Default FragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default Constructor!" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Name Constructor!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other)
{
    this->hitPoints = other.getHitPoints();
    this->energyPoints = other.getEnergyPoints();
    this->attackDamage = other.getAttackDamage();
    std::cout << "FragTrap Copy Constructor!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
    }
    std::cout << "FragTrap Copy Assignment Operator!" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "FragTrap " << name << " softly cannot attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " softly attacks " << target << ", causing " 
              << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
