#include <iostream>
#include "../headers/Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Fixed::Fixed(void) 
{
	_value = 0;
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
		this->_value = obj.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int integer)
{
	this->_value = integer << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// METHODS
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat (void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int	Fixed::toInt (void) const
{
	return (this->_value >> Fixed::_fractionalBits);
}

// STREAM OVERLOADS
std::ostream & operator<<(std::ostream & outfile, const Fixed & fixed)
{
    outfile << fixed.toFloat();
    return outfile;
}
