#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c (10);
	Fixed d = b * c;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b * c = " << d << std::endl;
	d = b / c;
	std::cout << "b / c = " << d << std::endl;
	d = b + c;
	std::cout << "b + c = " << d << std::endl;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Max a, b: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min a, b: " << Fixed::min(a, b) << std::endl;

	// Additional 
	Fixed defaultConstructor;
	std::cout << "default constructor value: " << defaultConstructor << std::endl;

	Fixed intConstructor(123);
	std::cout << "int constructor value: " << intConstructor << std::endl;

	Fixed floatConstructor(42.4219f);
	std::cout << "float constructor value: " << floatConstructor << std::endl;

	Fixed copyConstructor(intConstructor);
	std::cout << "copy constructor value: " << copyConstructor << std::endl;

	if (intConstructor > floatConstructor)
		std::cout << "123 is bigger than 42.4219" << std::endl;
	else
		std::cout << "123 is not bigger than 42.4219" << std::endl;

	if (intConstructor != floatConstructor)
		std::cout << "123 is not equal to 42.4219" << std::endl;
	else
		std::cout << "123 is equal to 42.4219" << std::endl;

	if (Fixed(5.534f) == Fixed(5.534f))
		std::cout << "5.534 is equal to 5.543" << std::endl;
	else
		std::cout << "5.534 is not equal to 5.543" << std::endl;

	return 0;
}
