#include <iostream>
#include "../headers/Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Fixed::Fixed(void) 
{
	_value_raw = 0;
}

Fixed::Fixed(const Fixed &other)
{
	this->operator=(other);
}

Fixed &Fixed::operator = (const Fixed &obj)
{
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
	return ;
}

// METHODS
int Fixed::getRawBits() const
{
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

bool	Fixed::operator>(Fixed const &right_hand_side) const
{
	return (this->getRawBits() > right_hand_side.getRawBits());
}

bool	Fixed::operator>=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() >= right_hand_side.getRawBits());
}

bool	Fixed::operator<(Fixed const &right_hand_side) const
{
	return (this->getRawBits() < right_hand_side.getRawBits());
}

bool	Fixed::operator<=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() <= right_hand_side.getRawBits());
}

bool	Fixed::operator==(Fixed const &right_hand_side) const
{
	return (this->getRawBits() == right_hand_side.getRawBits());
}

bool	Fixed::operator!=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() != right_hand_side.getRawBits());
}


// arithmetic

Fixed Fixed::operator+(Fixed const &right_hand_side)
{
	return (this->toFloat() + right_hand_side.toFloat());
}

Fixed Fixed::operator-(Fixed const &right_hand_side)
{
	return (this->toFloat() - right_hand_side.toFloat());
}

Fixed Fixed::operator*(Fixed const &right_hand_side)
{
	return (this->toFloat() * right_hand_side.toFloat());
}

Fixed Fixed::operator/(Fixed const &right_hand_side)
{
	if (!right_hand_side.toFloat())
	{
		std::cout << "Can't divide by ";
		return Fixed(0);
	}
	return (this->toFloat() / right_hand_side.toFloat());
}

// increment|decrement
Fixed	&Fixed::operator++(void)
{
	this->_value_raw++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_value_raw--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed anchor(*this);
	this->_value_raw++;
	return (anchor);
}

Fixed	Fixed::operator--(int)
{
	Fixed anchor(*this);
	this->_value_raw--;
	return (anchor);
}
