#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int integer);
		Fixed(const float f);
		~Fixed(void);
		Fixed& operator=(const Fixed &other);
		float	toFloat (void) const;
		int		toInt (void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	private:
		int _value_raw;
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &outfile, Fixed const &instance);

#endif
