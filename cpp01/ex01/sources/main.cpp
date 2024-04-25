#include "../headers/Zombie.hpp"

int main(void)
{
    Zombie *john = zombieHorde(5, "Clone");

    for (int i = 0; i < 5; i++)
    {
        john[i].announce();
    }
    delete [] john;
    return (0);
}
