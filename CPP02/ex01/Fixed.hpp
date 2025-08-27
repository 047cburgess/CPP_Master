#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class	Fixed 
{
	private:
		int	_fixedPointValue;
		static const int _numFractionalBits = 8;
	public:
		Fixed(void); // default constructor
		Fixed(const Fixed &other); // copy constructor
		Fixed& operator=(const Fixed& other); // assignment overload 
		Fixed(const int num); // constructor
		Fixed(const float num); // constructor
		~Fixed(void); // destructor
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

# endif
