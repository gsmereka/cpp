#include "../headers/ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clapTrap("Carlitos");
    clapTrap.showStatus();

    clapTrap.attack("Smoke");
    clapTrap.showStatus();

    clapTrap.takeDamage(5);
    clapTrap.showStatus();

    clapTrap.beRepaired(3);
    clapTrap.showStatus();

    clapTrap.attack("Bob");
    clapTrap.showStatus();

    clapTrap.takeDamage(10);
    clapTrap.showStatus();

    clapTrap.beRepaired(5);
    clapTrap.showStatus();

    std::cout << std::endl;
    std::cout << "Name: " << clapTrap.getName() << std::endl;
    std::cout << "Hit Points: " << clapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clapTrap.getAttackDamage() << std::endl;

    return 0;
}
