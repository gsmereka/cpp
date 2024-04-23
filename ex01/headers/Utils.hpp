#ifndef UTILS_HPP

# include "PhoneBook.hpp"

// void printHeader(void);
// std::string getValueFromCIN(void);
// bool validateNames(std::string const name);
// void printListContacts(PhoneBook const &book);
void	printContactInfo(Contact const &contact);
// bool validateNumber(std::string const number);
// bool validateContact(Contact const &newContact);
void	printContactsPreview(PhoneBook const &book);
int 	getIndexInput();
bool 	validateContact(Contact const &newContact);
Contact getNewContact(void);

#endif