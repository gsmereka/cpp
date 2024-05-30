#include <iostream>
#include "../headers/Intern.hpp"
#include "../headers/Bureaucrat.hpp"

void testInternCreation()
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form)
    {
        delete form;
    }

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    if (form)
    {
		Bureaucrat carlitos;
		std::cout << carlitos << std::endl ;
		try
		{
			for (int i = 0; i < 99; i++)
				carlitos.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		carlitos.signForm(*form);
		carlitos.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("non-existent form", "Nowhere");
    if (form)
    {

        delete form;
    }
}

int main(void)
{
    testInternCreation();
    return 0;
}
