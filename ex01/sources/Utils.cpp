#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include "../headers/Utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

void printContactInfo(Contact const &contact)
{
	std::cout << "\nContact Info\n" << std::endl;
    std::cout << "First Name :";
	std::cout << contact.getFirstName() << std::endl;
    std::cout << "Last Name :";
	std::cout << contact.getLastName() << std::endl;
    std::cout << "Nick Name :";
	std::cout << contact.getNickName() << std::endl;
    std::cout << "Phone Number :";
	std::cout << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret :";
	std::cout << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void printContactsPreview(PhoneBook const &book)
{
    std::cout << "contact" << std::endl;
}

int	getIndexInput()
{
	std::string input;

	std::cin >> input;
	if (input.length() != 1)
		return (-1);
	if (!isdigit(input[0]) && input[0] != '0')
		return (-1);
	if (stoi(input) < 0 || stoi(input) >= 8)
		return (-1);
	return stoi(input);
}

bool validateContact(Contact const &newContact)
{
	return true;
}

Contact getNewContact(void)
{
	std::string 	question[5] = {"First Name: ", "Last Name: ", "Nick Name: ", "Phone Number: ", "Darkest Secret: "};
	std::string		word[5];
	bool			is_empty;
	std::string		answer;

	for (int stage = 0; stage < 5; stage++)
	{
		std::cout << question[stage];
		std::cin >> answer;
		is_empty = true;
		for (int c = 0; c < answer.length(); c++)
		{
			if (!answer[c])
				break;
			if (!std::isspace(answer[c]))
            {
                is_empty = false;
                break;
            }
		}
		if (is_empty)
		{
			std::cout << "No Empty Values Allowed, try again!" << std::endl;
			return (getNewContact());
		}
		word[stage] = answer;
	}
	Contact	newContact(word[0], word[1], word[2], word[3], word[4]);
	return newContact;
}
