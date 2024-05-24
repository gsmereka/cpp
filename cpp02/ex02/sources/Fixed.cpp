#include <iostream>
#include "../headers/Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Fixed::Fixed(void) 
{
	_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	this->operator=(other);
}

Fixed &Fixed::operator = (const Fixed &obj)
{
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
	return ;
}

// METHODS
int Fixed::getRawBits() const
{
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

// min|max

Fixed const	&Fixed::min(Fixed const &number1, Fixed const &number2)
{
	if (number1 < number2)
		return (number1);
	return (number2);
}

Fixed const	&Fixed::max(Fixed const &number1, Fixed const &number2)
{
	if (number1 > number2)
		return (number1);
	return (number2);
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2)
{
	if (number1 < number2)
		return (number1);
	return (number2);
}

Fixed &Fixed::max(Fixed &number1, Fixed  &number2)
{
	if (number1 > number2)
		return (number1);
	return (number2);
}

// STREAM OVERLOAD
std::ostream & operator<<(std::ostream & outfile, const Fixed & fixed)
{
    outfile << fixed.toFloat();
    return outfile;
}

// OPERATORS

// comparison

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}


// arithmetic

Fixed Fixed::operator+(Fixed const &rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

// increment|decrement
Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed anchor(*this);
	this->_value++;
	return (anchor);
}

Fixed	Fixed::operator--(int)
{
	Fixed anchor(*this);
	this->_value--;
	return (anchor);
}
