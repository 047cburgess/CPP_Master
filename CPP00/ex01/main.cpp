#include "PhoneBook.hpp"
#include <string>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (1)
	{
		phonebook.getInput(command, "Enter a command (ADD, SEARCH, EXIT): ");
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
	}
}
