#include "../headers/Intern.hpp"

// Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(const Intern &other) {
    *this = other;
}

// Assignment Operator
Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Function to create ShrubberyCreationForm
AForm* Intern::createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

// Function to create RobotomyRequestForm
AForm* Intern::createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

// Function to create PresidentialPardonForm
AForm* Intern::createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// makeForm function
AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    FormCreation forms[] = {
        { "shrubbery creation", &Intern::createShrubbery },
        { "robotomy request", &Intern::createRobotomy },
        { "presidential pardon", &Intern::createPardon }
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Error: Form name " << formName << " not recognized." << std::endl;
    return nullptr;
}
