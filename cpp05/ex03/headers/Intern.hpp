#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

	class Intern
	{
		public:
			Intern();
			Intern(Intern &other);
			Intern &operator=(Intern &other);
			~Intern();

			AForm	*makeForm(std::string formName, std::string target);

		private:
			AForm	*createShrubbery(std::string target);
			AForm	*createRobotomy(std::string target);
			AForm	*createPardon(std::string target);
			AForm	*returnNull( std::string target);
	};

#endif // INTERN_HPP