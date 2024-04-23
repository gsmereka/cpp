#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include "../headers/Utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

PhoneBook::PhoneBook(void) : bookSize(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

Contact PhoneBook::getContact(unsigned int index) const
{
  return this->book[index];
}

unsigned int PhoneBook::getBookSize(void)
{
	return this->bookSize;
}

void PhoneBook::add(void)
{
	Contact newContact = getNewContact();

	if (validateContact(newContact))
	{
		this->book[this->bookSize % 8] = newContact;
		this->bookSize += 1;
		return;
	}
	return;
}

void PhoneBook::search(PhoneBook const &book)
{
	std::string	inputIndex;
	unsigned int	index;

	if (!book.bookSize)
	{
		std::cout << "The PHONEBOOK is empty!!\n" << std::endl;
		return;
	}
	printContactsPreview(book);
	while (true)
	{
		std::cout << "Input contact's index wanted: ";
		index = getIndexInput();
		if (index != -1)
			break;
		std::cout << '\n';
		std::cout << "Index must a positive number and betwen 0-8 range !!!\n";
		std::cout << '\n';
	}
	printContactInfo(book.getContact(index));
}
