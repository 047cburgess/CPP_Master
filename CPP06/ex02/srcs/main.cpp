#include "Base.hpp"
#include <cstdlib>
#include <ctime>

# define count 10

int	main(void)
{
	std::srand(time(0));
	Base*	random[count];


	for (int i = 0; i < count; i++)
	{
		random[i] = generate();
		identify(random[i]);
		identify(*random[i]);
	}

	for (int i = 0; i < count; i++)
		delete random[i];
}
