#include <iostream>
#include "../headers/Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
				std::string phoneNumber, std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
	this->phoneNumber = phoneNumber;
	this->nickName = nickName;
	this->lastName = lastName;
	this->firstName = firstName;
}

std::string Contact::getFirstName(void)
{
	return this->firstName;
}

std::string Contact::getPhoneNumber(void)
{
	return this->phoneNumber;
}

std::string Contact::getNickName(void)
{
	return this->nickName;
}

std::string Contact::getLastName(void)
{
	return this->lastName;
}

std::string Contact::getDarkestSecret(void)
{
	return this->darkestSecret;
}