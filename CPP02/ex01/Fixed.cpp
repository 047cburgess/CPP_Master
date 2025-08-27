#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// Integer constructor
Fixed::Fixed(const int num): _fixedPointValue(num << _numFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Floating point constructor
Fixed::Fixed(const float num): _fixedPointValue(roundf(num * (1 << _numFractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _numFractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> _numFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}
