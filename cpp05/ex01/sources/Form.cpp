#include "../headers/Form.hpp"

// Constructors
Form::Form() : name("Default Form"), signedStatus(false), gradeToSign(10), gradeToExecute(10)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Initialized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Copy assingment constructor called" << std::endl;
    if (this != &other)
    {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

// destructor
Form::~Form()
{
    std::cout << "Default destructor called" << std::endl;
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
        throw GradeTooLowException();
    signedStatus = true;
}


// Exeptions
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
