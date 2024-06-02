#include "../headers/Bureaucrat.hpp"
#include <iostream>

static void testFailToCreateBureaucrat();
static void testSucessToCreateBureaucrat();
static void testIncrementGradeFail();
static void testDecrementGradeFail();

int main(void)
{
	testFailToCreateBureaucrat();
	testSucessToCreateBureaucrat();
	testIncrementGradeFail();
	testDecrementGradeFail();
	return (0);
}

static void testFailToCreateBureaucrat()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "⚠️  Attempting to create a Bureaucrat, but fail:  ⚠️" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	
	try
	{
		std::cout << "The next line should throw an exception:" << std::endl << std::endl;
		Bureaucrat bob("Bob", 0);

		std::cout << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}

static void testSucessToCreateBureaucrat()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << " ⚠️  Attempting to create a Bureaucrat: ⚠️" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	
	try
	{
		Bureaucrat bob("Bob", 1);

		std::cout << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}


static void testIncrementGradeFail()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << " ⚠️  Attempting to increment a grade, but fail: ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat bob("Bob", 1);

		std::cout << bob << std::endl;

		std::cout << "The next line should throw an exception:" << std::endl << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}

static void testDecrementGradeFail()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to decrement a grade, but fail:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat bob("Bob", 150);

		std::cout << bob << std::endl;

		std::cout << "The next line should throw an exception:" << std::endl << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}
