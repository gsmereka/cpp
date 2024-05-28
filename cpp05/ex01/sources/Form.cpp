#include "../headers/Form.hpp"

// Constructors
Form::Form() : name("Default Form"), signedStatus(false), gradeToSign(10), gradeToExecute(10)
{
    std::cout << "\033[32mDefault Form constructor called\033[0m\033[0m" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "\033[32mInitialized Form constructor called\033[0m" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.getName()), signedStatus(other.isSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
    std::cout << "\033[32mForm Copy constructor called\033[0m" << std::endl;
}

Form &Form::operator=(const Form &other)
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
Form::~Form()
{
    std::cout << "\033[31mDefault Form destructor called\033[0m" << std::endl;
}


// Getters
const std::string &Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}


// Be Signed
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooHighException();
    signedStatus = true;
}


// exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

// Stream overload
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
