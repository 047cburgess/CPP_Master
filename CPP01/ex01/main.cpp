#include "Zombie.hpp"
#include <iostream>

# define SIZE 5

int	main(void)
{
	Zombie* my_zombies = zombieHorde(SIZE, "Casey");

	for (int i = 0; i < SIZE; i++)
		my_zombies[i].announce();

	std::cout << "Before delete" << std::endl;
	delete [] my_zombies;
	std::cout << "After delete" << std::endl;
}
