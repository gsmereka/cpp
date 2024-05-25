#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"
#include <iostream>

void	testing_construction_and_destruction(void)
{
	std::cout << "Creating ClapTrap ct(\"Clappy\"):" << std::endl;
	ClapTrap ct("Clappy");
	std::cout << std::endl;
	std::cout << "Creating ScavTrap st(\"Scavvy\"):" << std::endl;
	ScavTrap st("Scavvy");
	std::cout << std::endl;
	std::cout << "Creating FragTrap st(\"Fraggy\"):" << std::endl;
	ScavTrap st("Fraggy");
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "CONSTRUCTION / DESTRUCTION" << std::endl;
	testing_construction_and_destruction();
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING CLAPTRAP" << std::endl;
    ClapTrap ct("Clappy");
    ct.attack("target");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.showStatus();
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

    std::cout << "TESTING SCAVTRAP" << std::endl;
    ScavTrap st("Scavvy");
    st.attack("target");
    st.guardGate();
    st.takeDamage(30);
    st.beRepaired(20);
    st.showStatus();
	st.guardGate();
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING FRAGTRAP" << std::endl;
    FragTrap ft("Fraggy");
    ft.attack("target");
    ft.highFivesGuys();
    ft.takeDamage(40);
    ft.beRepaired(30);
    ft.showStatus();
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
    return 0;
}