#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*	array_ptr;
	int	i;

	array_ptr = new Zombie[N];
	i = 0;
	while (i < N)
	{
		array_ptr[i].setName(name);
		i++;
	}
	return (array_ptr);
}
