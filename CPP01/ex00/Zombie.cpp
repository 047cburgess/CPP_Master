#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( std::string name ) : _name(name) {};

Zombie::~Zombie( void )
{
	std::cout << this->_name << " was destroyed." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

