#include "../headers/PresidentialPardonForm.hpp"
#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

// Copy
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}


// Action
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
