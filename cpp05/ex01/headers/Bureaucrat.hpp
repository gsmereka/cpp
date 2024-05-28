#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

// needs to include
class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat(void);
		Bureaucrat& operator=(const Bureaucrat &other);
		int 				getGrade(void) const;
		const std::string	&getName(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		// new function
		void				signForm(Form &form) const;

		// exceptions classes
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	private:
		const std::string	name;
		int					grade;
};

// STREAM OVERLOADS
std::ostream &operator<<(std::ostream &outfile, Bureaucrat const &instance);


#endif
