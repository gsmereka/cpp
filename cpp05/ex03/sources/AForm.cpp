#include "../headers/AForm.hpp"

// Constructors
AForm::AForm() : name("Default AForm"), signedStatus(false), gradeToSign(10), gradeToExecute(10)
{
    std::cout << "\033[32mDefault AForm constructor called\033[0m\033[0m" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "\033[32mInitialized AForm constructor called\033[0m" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.getName()), signedStatus(other.isSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
    std::cout << "\033[32mForm Copy constructor called\033[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "\033[32mForm Copy assingment constructor called\033[0m" << std::endl;
    if (this != &other)
    {
        const_cast<std::string&>(this->name) = other.getName();
        this->signedStatus = other.isSigned();
		const_cast<int&>(this->gradeToSign) = other.getGradeToSign();
		const_cast<int&>(this->gradeToExecute) = other.getGradeToExecute();
    }
    return *this;
}

// destructor
AForm::~AForm()
{
    std::cout << "\033[31mDefault AForm destructor called\033[0m" << std::endl;
}


// Getters
const std::string &AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return signedStatus;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}


// Be Signed
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooHighException();
    signedStatus = true;
}


// exceptions
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade too high!";
}

// Stream overload
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
