#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include "../headers/Utils.hpp"
#include <iostream>

#include <stdio.h>

int main(void)
{
    std::string input;
    PhoneBook   book;

    std::cout << "Wellcome to the PHONEBOOK" << std::endl;
    while (true)
    {
        std::cout << "Chose between ADD, SEARCH and EXIT" << std::endl;
        std::cin >> input;
        if (input.compare("ADD") == 0)
            book.add();
        else if (input.compare("SEARCH") == 0)
            PhoneBook::search(book);
        else if (input.compare("EXIT") == 0)
            break ;
    }
    return (0);
}
