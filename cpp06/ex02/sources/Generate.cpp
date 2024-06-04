#include "../headers/Base.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    srand(time(0));
    int choice = rand() % 3;

    switch (choice)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}