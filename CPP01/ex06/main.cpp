#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./harlFilter \"<complaint>\"" << std::endl;
		return (1);
	}
	Harl	my_harl;

	my_harl.complain(av[1]);
}
