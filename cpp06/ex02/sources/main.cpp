#include "../headers/Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void)
{
    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}


void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout <<  "A" << std::endl;
		return ;
	}	catch(...) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout <<  "B" << std::endl;
		return ;
	}	catch(...) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout <<  "C" << std::endl;
		return ;
	}
	catch (...) 
	{
		std::cout << "This class is not in my list of valid classes!\n";
	}
}

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