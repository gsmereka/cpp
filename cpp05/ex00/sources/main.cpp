#include "../headers/Bureaucrat.hpp"
#include <iostream>

static void testFailToSignForm();
static void testIncrementGradeFail();

int main(void)
{
	testFailToSignForm();
	testIncrementGradeFail();
	return 0;
}

static void testFailToSignForm()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "Attempting to sign a Form, but fail:" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	Bureaucrat bob("Bob", 100);

	std::cout << bob << std::endl;

	std::cout << "The next line should throw an exception:" << std::endl << std::endl;
	// bob.signForm(formA);
}

static void testIncrementGradeFail()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "Attempting to increment a grade, but fail:" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat bob("Bob", 1);

		std::cout << bob << std::endl;

		std::cout << "The next line should throw an exception:" << std::endl << std::endl;
		bob.incrementGrade();
		// bob.signForm(formA);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}
