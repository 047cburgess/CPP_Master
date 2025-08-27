#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

// mini constructor initialisation list
PhoneBook::PhoneBook() : _contactCount(0), _index(0) {};

int	PhoneBook::getInput(std::string &input, std::string prompt) const
{
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cin.clear();
		std::clearerr(stdin);
		return (0);
	}
	if (input.empty())
	{
		std::cin.clear();
		std::cerr << "Error: Empty field." << std::endl;
		std::clearerr(stdin);
		return (0);
	}
	return (1);		
}

// Add a new contact to phonebook
void	PhoneBook::addContact()
{
	Contact	new_contact;
	std::string	user_input;
	
	if (!getInput(user_input, "Enter first name: "))
		return ;
	new_contact.setFirstName(user_input);

	if (!getInput(user_input, "Enter last name: "))
		return ;
	new_contact.setLastName(user_input);

	if (!getInput(user_input, "Enter nick name: "))
		return ;
	new_contact.setNickName(user_input);

	if (!getInput(user_input, "Enter phone number: "))
		return ;
	new_contact.setPhoneNumber(user_input);

	if (!getInput(user_input, "Enter your darkest secret: "))
		return ;
	new_contact.setDarkestSecret(user_input);

	// save finished contact to the phonebook
	_contacts[_index] = new_contact;
	if (_contactCount < MAX_CONTACTS)
		_contactCount++;
	if (_index == MAX_CONTACTS - 1)
		_index = 0;
	else
		_index++;
}

void	PhoneBook::searchContact() const
{
	std::string contact_index;
	int	str_to_int;

	str_to_int = 0;
	if (_contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}
	this->_displayContacts();
	if (!getInput(contact_index, "Provide desired contact index: "))
		return ;
	if (!this->_checkIndex(contact_index))
		return ;
	str_to_int = contact_index[0] - 48;
	this->_displayContactIndex(str_to_int);
}

void	PhoneBook::_displayContacts() const
{
	// Print the table headers
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std:: setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;

	// Display all the contacts
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|"
		<< std::setw(10) << _truncateField(_contacts[i].getFirstName()) << "|"
		<< std::setw(10) << _truncateField(_contacts[i].getLastName()) << "|"
		<< std::setw(10) << _truncateField(_contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::_displayContactIndex(int index) const
{
	// Check if the given index is valid
	if (index < 0 || index >= _contactCount)
	{
		std::cerr << "Invalid index." << std::endl;
		return ;
	}

	// Print the details of the valid index
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

int	PhoneBook::_getContactCount() const
{
	return (_contactCount);
}


std::string PhoneBook::_truncateField(const std::string &str) const
{
	if (str.length() > MAX_FIELD_LENGTH)
		return (str.substr(0, MAX_FIELD_LENGTH - 1) + ".");
	else
		return (str);
}


int	PhoneBook::_checkIndex(const std::string &str) const
{
	//check length is one
	if (str.length() != 1)
	{
		std::cerr << "Invalid index." << std::endl;
		return (0);
	}
	//check it's between 0 and contactcount - 1
	if (str[0] < '0' || str[0] > (_contactCount - 1 + 48))
	{
		std::cerr << "Invalid index." << std::endl;
		return (0);
	}
	return (1);
}
