#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void execute(Bureaucrat const &executor) const;

private:
    const std::string target;
};

#endif
