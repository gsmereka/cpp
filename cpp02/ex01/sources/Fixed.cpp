#include <iostream>
#include "../headers/Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTOR
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

Fixed::Fixed(const int integer)
{
	this->_value_raw = integer << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_value_raw = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// METHODS
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value_raw;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value_raw = raw;
}

float	Fixed::toFloat (void) const
{
	return static_cast<float>(_value_raw) / (1 << _fractionalBits);
}

int	Fixed::toInt (void) const
{
	return (this->_value_raw >> Fixed::_fractionalBits);
}

// STREAM OVERLOADS
std::ostream & operator<<(std::ostream & outfile, const Fixed & fixed)
{
    outfile << fixed.toFloat();
    return outfile;
}
