#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook   book;

    Contact cont("fgfsdgfsdgdsg", "lastName", "nickName",
				"phoneNumber", "darkestSecret");
    std::cout << cont.getFirstName() << std::endl;
}