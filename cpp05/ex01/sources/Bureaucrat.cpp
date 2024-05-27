#include <iostream>
#include "../headers/Bureaucrat.hpp"

// Constructors 

Bureaucrat::Bureaucrat(void) : name("Default"), grade(100)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	std::cout << "Name and Grade constructor called" << std::endl;
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		grade = obj.getGrade();
	}
	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

// GETERS
const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// Increment | decrement

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
	grade++;
}

// STREAM OVERLOADS

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

// New function
void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Exeptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}