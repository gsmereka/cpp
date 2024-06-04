#include "../headers/Intern.hpp"

// Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern( Intern &other)
{
	*this = other;
}

// Assignment Operator
Intern &Intern::operator=( Intern &other)
{
    if (this != &other)
    {
		return *this;
    }
	return *this;
}

// Destructor
Intern::~Intern() {}

// Form Creators
AForm* Intern::createShrubbery( std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy( std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon( std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::returnNull( std::string target)
{
	(void)target;
	return NULL;
}

// makeForm function
AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm	*(Intern::*functions[4])(std::string target) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon,
		&Intern::returnNull
	};
	
	std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int index = 0;
	while (index < 3 && formName.compare(formNames[index]))
		index++;
	return (this->*functions[index])(target);
}
