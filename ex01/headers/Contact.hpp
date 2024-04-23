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

		std::string	getDarkestSecret() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
