#include "../headers/RobotomyRequestForm.hpp"
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 72, 45), target(target) {}

// Copy
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}


// Action
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooHighException();

	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
