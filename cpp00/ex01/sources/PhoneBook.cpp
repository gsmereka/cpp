#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"
#include "../headers/Utils.hpp"

PhoneBook::PhoneBook(void)
{
	bookIndex = 0;
	bookLimit = 8;
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

unsigned int PhoneBook::getbookIndex(void) const
{
	return this->bookIndex;
}

void PhoneBook::add(void)
{
	Contact 		newContact = getNewContact();

	if (!validateContact(newContact))
		return;
	this->book[this->bookIndex % this->bookLimit] = newContact;
	this->bookIndex += 1;
}

void PhoneBook::search(PhoneBook const &book)
{
	unsigned int	indexLimit = book.bookIndex;
	unsigned int	index;
	std::string		input;

	if (indexLimit > book.bookLimit)
		indexLimit = book.bookLimit;
	if (!indexLimit)
	{
		std::cout << "The PHONEBOOK is empty!!\n" << std::endl;
		return;
	}
	printContactsPreview(book, indexLimit);
	while (true)
	{
		std::cout << "Input contact's index wanted: ";
		std::cin >> input;
		if	(isOnlyNumber(input))
		{
			std::stringstream ss(input);
			ss >> index;
			if (index < indexLimit)
				break;
		}
		std::cout << '\n';
		std::cout << "Index Unavailable!\n";
		std::cout << '\n';
	}
	printContactInfo(book.getContact(index));
}
