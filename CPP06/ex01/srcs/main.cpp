#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
# include <stdint.h>


std::ostream& operator<<(std::ostream& os, const Data& other)
{
	os << other.i << std::endl;
	os << other.c << std::endl;
	os << other.s << std::endl;
	os << other.d << std::endl;
	os << other.f << std::endl;
	return (os);
}

int	main(void)
{
	Data my_data;

	my_data.i = 10;
	my_data.c = 'a';
	my_data.s = "hey";
	my_data.d = 42.2;
	my_data.f = 24.2f;

	std::cout << "---my_data---" << std::endl;
	std::cout << my_data << std::endl;
	uintptr_t forward = Serializer::serialize(&my_data);

	Data* back = Serializer::deserialize(forward);
	std::cout << "---pointer after serialize + deserialize my_data---" << std::endl;
	std::cout << *back << std::endl;

	std::cout << "---changing i to 20, s to 'hello world'---" << std::endl;
	my_data.i = 20;
	my_data.s = "hello world";
	std::cout << "---my_data---" << std::endl;
	std::cout << my_data << std::endl;
	std::cout << "---pointer to my_data---" << std::endl;
	std::cout << *back << std::endl;
}
