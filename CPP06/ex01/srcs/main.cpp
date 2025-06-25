#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
# include <stdint.h>

int	main(void)
{
	Data my_data;

	my_data.i = 10;
	my_data.c = 'a';
	my_data.s = "hey";
	my_data.d = 42.2;
	my_data.f = 24.2f;

	uintptr_t	ptr = reinterpret_cast<uintptr_t>(&my_data);

	
	Data* returned = reinterpret_cast<Data>(ptr);
}
