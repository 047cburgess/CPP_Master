#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	newZombie( std::string name )
{
	Zombie	*new_zombie;
	new_zombie = new Zombie(name);
	return (new_zombie);
}
