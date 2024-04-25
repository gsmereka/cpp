#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "./Weapon.hpp"

class HumanA
{
    public:
        HumanA(void);
        ~HumanA(void);
        HumanA(std::string name);
        void setName(std::string name);
        void announce(void);
    private:
        std::string name;
};

HumanA *newZombie(std::string name);
void randomChump(std::string name);
HumanA	*zombieHorde(int N, std::string name);

#endif
