#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_debug(void)
{
	std::cout << "MY DEBUG" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "MY INFO" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "MY WARNING" << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "MY ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*funcs[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cerr << "Unrecognised complaint <" << level << ">" << std::endl;
}
