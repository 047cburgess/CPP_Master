#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

#define MAX_CONTACTS 8
#define MAX_FIELD_LENGTH 10

class	PhoneBook
{
	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;
		int	getInput(std::string &input, std::string prompt) const;

	private:
		Contact	_contacts[8];
		int	_contactCount;
		int	_index;
		int	_getContactCount() const;
		void	_displayContacts() const;
		void	_displayContactIndex(int index) const;
		std::string _truncateField(const std::string &str) const;
		int	_checkIndex(const std::string &str) const;
};

#endif
