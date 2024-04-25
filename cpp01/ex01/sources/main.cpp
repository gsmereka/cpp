#include "../headers/Zombie.hpp"

int main(void)
{
    Zombie *clones = zombieHorde(5, "Clone");

    for (int i = 0; i < 5; i++)
    {
        clones[i].announce();
    }
    delete [] clones;
    return (0);
}
