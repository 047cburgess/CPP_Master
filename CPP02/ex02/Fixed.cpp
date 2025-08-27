#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int num): _fixedPointValue(num << _numFractionalBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _fixedPointValue(roundf(num * (1 << _numFractionalBits)))
{
	//std::cout << "Float constructor called" << std::endl;
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

Fixed	Fixed::operator+(Fixed const& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const& other) const
{
	Fixed	result;
	
	long	bitsCalculation = (long)this->getRawBits() * (long)other.getRawBits();
	result.setRawBits(bitsCalculation >> _numFractionalBits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const& other) const
{
	Fixed	result;

	long	bitsCalculation = ((long)this->getRawBits() << _numFractionalBits) / other.getRawBits();
	result.setRawBits(bitsCalculation);
	return (result);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

// pre increment
Fixed&	Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return (*this);
}

// pre decrement
Fixed&	Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return (*this);
}

// post increment
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++this->_fixedPointValue;
	return (temp);
}

// post decrement
Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->_fixedPointValue;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
