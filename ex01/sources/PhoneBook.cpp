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

Contact PhoneBook::getContact(unsigned int index)
{
  return this->book[index];
}

unsigned int PhoneBook::getBookSize(void)
{
	return this->bookSize;
}

bool PhoneBook::add(void)
{
	Contact newContact = getNewContact();

	// if (validateContact(newContact))
	// {
	// 	this->book[this->bookSize % 8] = newContact;
	// 	this->bookSize += 1;
	// 	return true;
	// }
	return false;
}

void PhoneBook::search(PhoneBook const &book)
{
//   std::string inputIndex;
//   unsigned int index;

//   printHeader();
//   printListContacts(book);

//   if (!book.bookSize) {
//     return;
//   }

//   while (true) {
//     std::cout << "Input contact's index wanted: ";
//     inputIndex = getValueFromCIN();

//     if (validateNumber(inputIndex)) {
//       break;
//     }

//     std::cerr << '\n';
//     std::cerr << "Index must a positive number !!!\n";
//     std::cerr << '\n';
//   }

//   index = std::atoi(inputIndex.c_str());

//   if (index > 7 || index >= book.getBookSize()) {
//     std::cerr << '\n';
//     std::cerr << "Index out of range !!!\n";
//     return;
//   }
//   printContactInformation(book.getContact(index));
}
