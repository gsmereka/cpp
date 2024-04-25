#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
    public:
        Weapon(void);
        ~Weapon(void);
        Weapon(std::string name);
        void        setType(std::string type);
        std::string getType(void);
    private:
        std::string type;
};


#endif
