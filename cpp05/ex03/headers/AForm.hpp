#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

// needs to include
class Bureaucrat; 

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		// exceptions classes
		class GradeTooHighException : public std::exception 
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	private:
		const std::string name;
		bool signedStatus;
		const int gradeToSign;
		const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
