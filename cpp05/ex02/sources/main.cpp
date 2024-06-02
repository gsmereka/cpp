#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include <iostream>

static void testFailToSignShrubberyCreationForm();
static void testSuccessfullySignShrubberyCreationForm();
static void testFailToExecuteShrubberyCreationForm();
static void testSuccesfullyToExecuteShrubberyCreationForm();

static void testFailToSignRobotomyRequestForm();
static void testSuccessfullySignRobotomyRequestForm();
static void testFailToExecuteRobotomyRequestForm();
static void testSuccesfullyToExecuteRobotomyRequestForm();

static void testFailToSignPresidentialPardonForm();
static void testSuccessfullySignPresidentialPardonForm();
static void testFailToExecutePresidentialPardonForm();
static void testSuccesfullyToExecutePresidentialPardonForm();


int main(void)
{
	// ShrubberyCreationForm
	testFailToSignShrubberyCreationForm();
	testSuccessfullySignShrubberyCreationForm();
	testFailToExecuteShrubberyCreationForm();
	testSuccesfullyToExecuteShrubberyCreationForm();

	// RobotomyRequestForm
	testFailToSignRobotomyRequestForm();
	testSuccessfullySignRobotomyRequestForm();
	testFailToExecuteRobotomyRequestForm();
	testSuccesfullyToExecuteRobotomyRequestForm();

	// PresidentialPardonForm
	testFailToSignPresidentialPardonForm();
	testSuccessfullySignPresidentialPardonForm();
	testFailToExecutePresidentialPardonForm();
	testSuccesfullyToExecutePresidentialPardonForm();

	return (0);
}

// ShrubberyCreationForm
static void testFailToSignShrubberyCreationForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to sign a ShrubberyCreationForm, but fail:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm form("Home");

		std::cout << form << std::endl;
		std::cout << bob << std::endl;

		std::cout << "The next line should throw an exception:" << std::endl << std::endl;
		bob.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccessfullySignShrubberyCreationForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully sign a ShrubberyCreationForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 140);
		ShrubberyCreationForm form("Garden");

		std::cout << form << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		std::cout << "John attempts to sign ShrubberyCreationForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to sign ShrubberyCreationForm again:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testFailToExecuteShrubberyCreationForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to Fail to execute a ShrubberyCreationForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 138);
		ShrubberyCreationForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign ShrubberyCreationForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute ShrubberyCreationForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccesfullyToExecuteShrubberyCreationForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully execute a ShrubberyCreationForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 137);
		ShrubberyCreationForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign ShrubberyCreationForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute ShrubberyCreationForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

// RobotomyRequestForm
static void testFailToSignRobotomyRequestForm()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "⚠️  Attempting to sign a RobotomyRequestForm, but fail:  ⚠️" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	Bureaucrat bob("Bob", 100);
	RobotomyRequestForm form("Home");

	std::cout << form << std::endl;
	std::cout << bob << std::endl;

	std::cout << "The next line should throw an exception:" << std::endl << std::endl;
	try
	{
		bob.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccessfullySignRobotomyRequestForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully sign a RobotomyRequestForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 72);
		RobotomyRequestForm form("Garden");

		std::cout << form << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		std::cout << "John attempts to sign RobotomyRequestForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to sign RobotomyRequestForm again:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testFailToExecuteRobotomyRequestForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to Fail to execute a RobotomyRequestForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 138);
		RobotomyRequestForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign RobotomyRequestForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute RobotomyRequestForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccesfullyToExecuteRobotomyRequestForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully execute a RobotomyRequestForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 1);
		RobotomyRequestForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign RobotomyRequestForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute RobotomyRequestForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}


static void testFailToSignPresidentialPardonForm()
{
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "⚠️  Attempting to sign a PresidentialPardonForm, but fail:  ⚠️" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
	Bureaucrat bob("Bob", 100);
	PresidentialPardonForm form("Home");

	std::cout << form << std::endl;
	std::cout << bob << std::endl;

	std::cout << "The next line should throw an exception:" << std::endl << std::endl;
	try {
		bob.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccessfullySignPresidentialPardonForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully sign a PresidentialPardonForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 25);
		PresidentialPardonForm form("Garden");

		std::cout << form << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		std::cout << "John attempts to sign PresidentialPardonForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to sign PresidentialPardonForm again:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

// PresidentialPardonForm
static void testFailToExecutePresidentialPardonForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to Fail to execute a PresidentialPardonForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 138);
		PresidentialPardonForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign PresidentialPardonForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute PresidentialPardonForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void testSuccesfullyToExecutePresidentialPardonForm()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "⚠️  Attempting to successfully execute a PresidentialPardonForm:  ⚠️" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------\n" << std::endl;
		Bureaucrat john("John", 1);
		PresidentialPardonForm form("Garden");

		std::cout << form << std::endl;
		std::cout << john << std::endl;

		std::cout << "John attempts to sign PresidentialPardonForm:" << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;

		std::cout << "John attempts to execute PresidentialPardonForm" << std::endl;
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
