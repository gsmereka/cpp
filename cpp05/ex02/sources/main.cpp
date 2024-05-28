#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include <iostream>


int main()
{
    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrubbery("home");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat john("John", 45);
        RobotomyRequestForm robotomy("Bender");
        john.signForm(robotomy);
        john.executeForm(robotomy);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 5);
        PresidentialPardonForm pardon("Ford Prefect");
        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

// static void testFailToSignForm();
// static void testSuccessfullySignForm();
// static void testInvalidHighGradeForm();
// static void testInvalidLowGradeForm();

// int main(void)
// {
// 	testFailToSignForm();
// 	testSuccessfullySignForm();
// 	testInvalidHighGradeForm();
// 	testInvalidLowGradeForm();
// 	return (0);
// }

// static void testFailToSignForm()
// {
// 	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 	std::cout << "⚠️  Attempting to sign a AForm, but fail:  ⚠️" << std::endl;
// 	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 	Bureaucrat bob("Bob", 100);
// 	AForm formA("FormA", 1, 1);

// 	std::cout << formA << std::endl;
// 	std::cout << bob << std::endl;

// 	std::cout << "The next line should throw an exception:" << std::endl << std::endl;
// 	bob.signForm(formA);
// }

// static void testSuccessfullySignForm()
// {
// 	try
// 	{
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		std::cout << "⚠️  Attempting to successfully sign a AForm:  ⚠️" << std::endl;
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		Bureaucrat john("John", 149);
// 		AForm formB("FormB", 150, 150);

// 		std::cout << formB << std::endl;

// 		john.decrementGrade();
// 		std::cout << john << std::endl;

// 		std::cout << "John attempts to sign FormB:" << std::endl;
// 		john.signForm(formB);
// 		std::cout << formB << std::endl;

// 		std::cout << "John attempts to sign FormB again:" << std::endl;
// 		john.signForm(formB);
// 		std::cout << formB << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// }

// static void testInvalidHighGradeForm()
// {
// 	try
// 	{
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		std::cout << "⚠️  Attempting to create a AForm with an invalid high grade (0):  ⚠️" << std::endl;
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		AForm invalidHighForm("InvalidHighForm", 0, 0);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// }

// static void testInvalidLowGradeForm()
// {
// 	try
// 	{
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		std::cout << "⚠️  Attempting to create a AForm with an invalid low grade (151):  ⚠️" << std::endl;
// 		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
// 		AForm invalidLowForm("InvalidLowForm", 151, 151);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// }
