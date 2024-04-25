#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "./Weapon.hpp"

class HumanB
{
    public:
        HumanB(void);
        ~HumanB(void);
        HumanB(std::string name);
        void setWeapon(Weapon &newWeapon);
        void attack();
    private:
        std::string name;
        Weapon *weapon;
};

#endif
