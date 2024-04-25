#include "../headers/Zombie.hpp"

Zombie::Zombie(void)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " died..." << std::endl;
	return;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	announce();
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}

void randomChump(std::string name)
{
	Zombie zombie(name);
}

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}