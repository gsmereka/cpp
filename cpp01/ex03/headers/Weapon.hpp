#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
    public:
        Weapon(void);
        ~Weapon(void);
        Weapon(std::string name);
        void setName(std::string name);
        void announce(void);
    private:
        std::string name;
};


#endif
