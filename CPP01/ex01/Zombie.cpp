#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << _getName() << " was destroyed." << std::endl;
}

std::string	Zombie::_getName( void ) const
{
	return (this->_name);
}

void	Zombie::setName( std::string &name )
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _getName() << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
