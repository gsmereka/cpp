#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include <iostream>

static void testFailToSignForm();
static void testSuccessfullySignForm();
static void testInvalidHighGradeForm();
static void testInvalidLowGradeForm();

int main(void)
{
	testFailToSignForm();
	testSuccessfullySignForm();
	testInvalidHighGradeForm();
	testInvalidLowGradeForm();
	return 0;
}

static void testFailToSignForm()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "⚠️  Attempting to sign a Form, but fail:  ⚠️" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	Bureaucrat bob("Bob", 100);
	Form formA("FormA", 1, 1);

	std::cout << formA << std::endl;
	std::cout << bob << std::endl;

	std::cout << "The next line should throw an exception:" << std::endl << std::endl;
	bob.signForm(formA);
}

static void testSuccessfullySignForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully sign a Form:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 149);
		Form formB("FormB", 150, 150);

		std::cout << formB << std::endl;

		john.decrementGrade();
		std::cout << john << std::endl;

		std::cout << "John attempts to sign FormB:" << std::endl;
		john.signForm(formB);
		std::cout << formB << std::endl;

		std::cout << "John attempts to sign FormB again:" << std::endl;
		john.signForm(formB);
		std::cout << formB << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testInvalidHighGradeForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to create a Form with an invalid high grade (0):  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Form invalidHighForm("InvalidHighForm", 0, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testInvalidLowGradeForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to create a Form with an invalid low grade (151):  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Form invalidLowForm("InvalidLowForm", 151, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
