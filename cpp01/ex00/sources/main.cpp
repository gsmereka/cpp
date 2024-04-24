#include "../headers/Zombie.hpp"

int main(void)
{
    Zombie *john = newZombie("John");
    randomChump("Claricio");
    delete john;
    return (0);
}
