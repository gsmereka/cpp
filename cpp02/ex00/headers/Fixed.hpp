#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		~Fixed(void);
		Fixed& operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(const int raw);
	private:
		int _value_raw;
		static const int _fractionalBits = 8;
};

#endif
