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

		// min|max
		static const Fixed	&min(Fixed const &value1, Fixed const &value2);
		static const Fixed	&max(Fixed const &value1, Fixed const &value2);
		static Fixed		&min(Fixed &value1, Fixed &value2);
		static Fixed		&max(Fixed &value1, Fixed &value2);

		// comparison
		bool	operator>(Fixed const &right_hand_side) const;
		bool	operator<(Fixed const &right_hand_side)const;
		bool	operator>=(Fixed const &right_hand_side)const;
		bool	operator<=(Fixed const &right_hand_side)const;
		bool	operator==(Fixed const &right_hand_side)const;
		bool	operator!=(Fixed const &right_hand_side)const;

		// arithmetic
		Fixed	operator+(Fixed const &right_hand_side);
		Fixed	operator-(Fixed const &right_hand_side);
		Fixed	operator/(Fixed const &right_hand_side);
		Fixed	operator*(Fixed const &right_hand_side);

		// increment|decrement
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
	private:
		int _value_raw;
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &outfile, Fixed const &instance);

#endif
