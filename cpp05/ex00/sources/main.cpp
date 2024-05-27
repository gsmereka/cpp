#include "../headers/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << "The next line should throw an exception:" << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;;
	}

	try
	{
		Bureaucrat john("John", 149);
		std::cout << john << std::endl;

		john.decrementGrade();
		std::cout << john << std::endl;
		std::cout << "The next line should throw an exception:" << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;;
	}

	try
	{
		std::cout << "The next line should throw an exception:" << std::endl;
		Bureaucrat invalidHigh("InvalidHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;;
	}

	try
	{
		std::cout << "The next line should throw an exception:" << std::endl;
		Bureaucrat invalidLow("InvalidLow", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;;
	}

	return (0);
}
