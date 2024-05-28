#include <iostream>
#include "../headers/Bureaucrat.hpp"

// Constructors 

Bureaucrat::Bureaucrat(void) : name("Default"), grade(100)
{
	std::cout << "\033[32mDefault Bureaucrat constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "\033[32mBureaucrat Copy constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	std::cout << "\033[32mInitialized Bureaucrat constructor called\033[0m" << std::endl;
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
	std::cout << "\033[32mBureaucrat Copy assignment operator called\033[0m" << std::endl;
	if (this != &obj)
	{
		const_cast<std::string&>(this->name) = obj.getName();
		grade = obj.getGrade();
	}
	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "\033[31mBureaucrat Destructor Called\033[0m" << std::endl;
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

#include <cstdio>

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
        std::cout << "\033[34m" << name << " signed " << form.getName() << "\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[33m" << name << " couldn’t sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
    }
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low!";
}