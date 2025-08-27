#include <iostream> // needed for "writing"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			av[i][j] = std::toupper(av[i][j]);
			j++;
		}
		std::cout << av[i]; 
		i++;
	}
	std::cout << std::endl;
}
