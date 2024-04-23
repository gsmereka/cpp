#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		Contact(std::string firstName, std::string lastName, std::string nickName,
				std::string phoneNumber, std::string darkestSecret);

		std::string	getDarkestSecret(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
