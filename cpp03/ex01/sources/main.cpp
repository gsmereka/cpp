#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include <iostream>

int main2()
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

int main() {
    // Teste de construção e destruição
    {
        std::cout << "Creating ClapTrap ct(\"Clappy\"):" << std::endl;
        ClapTrap ct("Clappy");
        std::cout << "Creating ScavTrap st(\"Scavvy\"):" << std::endl;
        ScavTrap st("Scavvy");
    } // Aqui os destruidores serão chamados automaticamente

    std::cout << std::endl;

    // Testando funcionalidades do ClapTrap
    ClapTrap ct("Clappy");
    ct.attack("target");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.showStatus();

    std::cout << std::endl;

    // Testando funcionalidades do ScavTrap
    ScavTrap st("Scavvy");
    st.attack("target");
    st.guardGate();
    st.takeDamage(30);
    st.beRepaired(20);
    st.showStatus();

    return 0;
}