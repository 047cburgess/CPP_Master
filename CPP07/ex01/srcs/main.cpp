#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void	print(T& a)
{
	std::cout << a;
}

template <typename T>
void	increment(T& i)
{
	i++;
}

int	main(void)
{
	int intArray[5] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, print<const int>);
	std::cout << std::endl;

	const int intArrayConst[5] = {1, 2, 3, 4, 5};
	::iter(intArrayConst, 5, print<const int>);
	std::cout << std::endl;

	::iter(intArray, 5, increment<int>);
	::iter(intArray, 5, print<int>);
	std::cout << std::endl;

	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	::iter(charArray, 5, print<char>);
	std::cout << std::endl;
	::iter(charArray, 5, increment<char>);
	::iter(charArray, 5, print<char>);
	std::cout << std::endl;
}
