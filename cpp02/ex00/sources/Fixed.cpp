#include <iostream>
#include "../headers/Fixed.hpp"

Fixed::Fixed(void) 
{
	_value_raw = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed &Fixed::operator = (const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_value_raw = obj.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value_raw;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value_raw = raw;
}


