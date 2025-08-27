#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Addr str: " << &str << std::endl; 
	std::cout << "Addr strPTR: " << &stringPTR << std::endl; 
	std::cout << "Addr strREF: " << &stringREF << std::endl; 

	std::cout << "Value str: " << str << std::endl;
	std::cout << "Value pointed to by strPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by strREF: " << stringREF << std::endl;
}
