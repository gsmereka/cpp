#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "./Weapon.hpp"

class HumanA
{
    public:
        HumanA(void);
        ~HumanA(void);
        HumanA(std::string name, Weapon &weapon);
        void setName(std::string name);
        void attack();
        void announce(void);
    private:
        std::string name;
        Weapon  *weapon;
};

#endif
