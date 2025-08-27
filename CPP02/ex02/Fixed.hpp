#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class	Fixed 
{
	private:
		int	_fixedPointValue;
		static const int	_numFractionalBits = 8;
	public:
		// Constructors
		Fixed(void); // default constructor
		Fixed(const Fixed &other); // copy constructor
		Fixed(const int num); // constructor
		Fixed(const float num); // constructor
		~Fixed(void);

		// Member functions
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		// Operator overloads
		Fixed& operator=(const Fixed& other); // assignment overload 

		// 6 Comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// 4 Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// 4 increment/decrement operators
		Fixed&	operator++(void); // pre increment
		Fixed	operator++(int); // post increment
		Fixed&	operator--(void); // pre decrement
		Fixed	operator--(int); // post decrement
					 //
		// Overloaded member functions (min, min, max, max)
		static	Fixed& min(Fixed& a, Fixed& b);
		static	const Fixed& min(const Fixed& a, const Fixed& b);
		static	Fixed& max(Fixed& a, Fixed& b);
		static	const Fixed& max(const Fixed& a, const Fixed& b);
};

// Other functions - non-class specific
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

# endif
