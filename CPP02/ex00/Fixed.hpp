#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed 
{
	private:
		int			_fixedPointValue;
		static const int	_numFractionalBits = 8;
	public:
		Fixed(void); // default constructor
		Fixed(const Fixed &other); // copy constructor
		Fixed& operator=(const Fixed& other); // assignment overload 
		~Fixed(void); // destructor
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

# endif
