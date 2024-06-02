#include "../headers/ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){}

// Functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooHighException();

	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile)
	{
		throw std::ios_base::failure("Failed to open file");
	}
	outfile << "      X\n";
	outfile << "     XXX\n";
	outfile << "    XXXXX\n";
	outfile << "   XXXXXXX     X\n";
	outfile << "  XXXXXXXXX   XXX\n";
	outfile << " XXXXXXXXXXX XXXXX\n";
	outfile << "      X     XXXXXXX\n";
	outfile << "      X        X\n";
	outfile << "************************\n";
	outfile.close();
}
