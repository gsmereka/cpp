#ifndef UTILS_HPP
# include "PhoneBook.hpp"
# include <iostream>
# include <iomanip>

bool            isOnlyNumber(std::string str);
void	        printContactInfo(Contact const &contact);
bool            isEmpty(std::string const str);
void	        printContactsPreview(PhoneBook const &book, unsigned int limit);
bool 	        validateContact(Contact const &newContact);
std::string     to_string(int value);
Contact         getNewContact(void);

#endif