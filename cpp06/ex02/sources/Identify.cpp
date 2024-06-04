#include "../headers/Base.hpp"
#include <iostream>
#include <typeinfo> 

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
    std::cout <<  "exception at A" << std::endl;
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout <<  "B" << std::endl;
		return ;
	}	catch(...) {}
    std::cout <<  "exception at B" << std::endl;
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
