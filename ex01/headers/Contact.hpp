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

		std::string	getDarkestSecret();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getFirstName();
		std::string	getLastName();
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
