#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapy1 = newZombie("Heapy1");
	heapy1->announce();
	
	randomChump("Stacky1");

	Zombie	*heapy2 = newZombie("Heapy2");
	heapy2->announce();

	randomChump("Stacky2");

	delete heapy1;
	delete heapy2;
}
