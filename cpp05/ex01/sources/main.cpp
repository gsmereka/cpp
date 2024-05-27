#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"



int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 1, 1);

        std::cout << formA << std::endl;

        std::cout << "The next line should throw an exception:" << std::endl;
        bob.incrementGrade(); // Should throw an exception
        std::cout << bob << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat john("John", 149);
        Form formB("FormB", 150, 150);

        std::cout << formB << std::endl;

        john.decrementGrade(); // Should not throw an exception
        std::cout << john << std::endl;

        std::cout << "John attempts to sign FormB:" << std::endl;
        john.signForm(formB);
        std::cout << formB << std::endl;

        std::cout << "John attempts to sign FormB again:" << std::endl;
        john.signForm(formB); // Should not change anything
        std::cout << formB << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to create a Form with an invalid high grade (0):" << std::endl;
        Form invalidHighForm("InvalidHighForm", 0, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to create a Form with an invalid low grade (151):" << std::endl;
        Form invalidLowForm("InvalidLowForm", 151, 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}