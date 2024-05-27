#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat(void);
		Bureaucrat& operator=(const Bureaucrat &other);
		int getGrade(void) const;
		const std::string &getName(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);
	private:
		const std::string	name;
		int					grade;
};

std::ostream &operator<<(std::ostream &outfile, Bureaucrat const &instance);

// Exception classes
class GradeTooHighException : public std::exception
{
	const char* what() const throw()
	{
		return "Grade is too high!";
	}
};

class GradeTooLowException : public std::exception
{
	const char* what() const throw()
	{
		return "Grade is too low!";
	}
};

#endif
