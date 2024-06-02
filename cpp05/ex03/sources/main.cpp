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
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("non-existent form", "Nowhere");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }
}

int main(void)
{
    testInternCreation();
    return 0;
}
