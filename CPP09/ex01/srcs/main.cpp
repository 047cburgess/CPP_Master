#include <stack>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"8 9 * 2\"" << std::endl;
	}

	std::stack<double> stack;

	std::isstream iss(av[1]);

	std::string buffer;

	while (1)
	{
		if (!iss >> buffer)
		{
			std::cout << "Invalid: " << buffer << std::endl;
			return (0);
		}
		if (is_digit(buffer))
			stack.push(atoi(buffer));
		else if (is_operator(buffer))
		{
			if (stack.size() < 2)
			{
				std::cout << "Invalid: operator with less than 2 nums in stack" << std::endl;
				return (0);
			}

			
		}
	}


	



}
