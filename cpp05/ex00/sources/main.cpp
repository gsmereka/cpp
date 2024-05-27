#include "../headers/Bureaucrat.hpp"

// #include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", -2);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// std::cout << bob << std::endl;
	return 0;
}

int main2()
{
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade(); // This should throw an exception
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 149);
        std::cout << john << std::endl;

        john.decrementGrade();
        std::cout << john << std::endl;

        john.decrementGrade(); // This should throw an exception
        std::cout << john << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidHigh("InvalidHigh", 0); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLow("InvalidLow", 151); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
