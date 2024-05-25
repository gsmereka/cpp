#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap ct("Clappy");
    ct.attack("target");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.showStatus();

    ScavTrap st("Scavvy");
    st.attack("target");
    st.guardGate();
    st.takeDamage(30);
    st.beRepaired(20);
    st.showStatus();

    return 0;
}
