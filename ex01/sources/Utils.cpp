#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include "../headers/Utils.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
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

void printWithLimit(std::string string)
{
	int limit = 10;

	if (string.length() >= limit)
	{
		string.resize(10);
		string[9] = '.';
	}
	std::cout << std::setw(10);
	std::cout << string << "|";
}

void printContactsPreview(PhoneBook const &book, unsigned int limit)
{
	Contact 	contact;
	std::cout << "|";
	printWithLimit("Index");
	printWithLimit("FirstName");
	printWithLimit("LastName");
	printWithLimit("NickName");
	std::cout << std::endl;

	for (unsigned int i = 0; i < limit; i++)
	{
		contact = book.getContact(i);
		std::cout << "|";
		printWithLimit(std::to_string(i));
		printWithLimit(contact.getFirstName());
		printWithLimit(contact.getLastName());
		printWithLimit(contact.getNickName());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool isOnlyNumber(std::string str)
{
	if (str.length() > 5)
		return (false);
	for (int a = 0; a < str.length(); a++)
	{
		if (!isdigit(str[a]))
		{
			return (false);
		}
	}
	return (true);
}


bool isEmpty(std::string const str)
{
	bool	is_empty = true;
	for (int c = 0; c < str.length(); c++)
	{
		if (!str[c])
			break;
		if (!std::isspace(str[c]))
		{
			is_empty = false;
			break;
		}
	}
	if (is_empty)
	{
		std::cout << "No Empty Values Allowed, try again!" << std::endl;
		return (true);
	}
	return (false);
}

bool validateContact(Contact const &newContact)
{
	if (isEmpty(newContact.getFirstName()))
		return (false);
	if (isEmpty(newContact.getLastName()))
		return (false);
	if (isEmpty(newContact.getNickName()))
		return (false);
	if (isEmpty(newContact.getPhoneNumber()))
		return (false);
	if (!isOnlyNumber(newContact.getPhoneNumber()))
	{
		std::cout << "\nOnly numbers allowed in Phone Number" << std::endl;
		return (false);
	}
	if (isEmpty(newContact.getDarkestSecret()))
		return (false);
	return (true);
}

Contact getNewContact(void)
{
	std::string 	question[5] = {"First Name: ", "Last Name: ", "Nick Name: ", "Phone Number: ", "Darkest Secret: "};
	std::string		word[5];
	std::string		answer;

	for (int stage = 0; stage < 5; stage++)
	{
		std::cout << question[stage];
		std::cin >> answer;
		word[stage] = answer;
	}
	Contact	newContact(word[0], word[1], word[2], word[3], word[4]);
	return (newContact);
}
