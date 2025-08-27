#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// Setter functions
void	Contact::setFirstName(const std::string &value)
{
	_firstName = value;
}

void	Contact::setLastName(const std::string &value)
{
	_lastName = value;
}

void	Contact::setPhoneNumber(const std::string &value)
{
	_phoneNumber = value;
}

void	Contact::setNickName(const std::string &value)
{
	_nickName = value;
}

void	Contact::setDarkestSecret(const std::string &value)
{
	_darkestSecret = value;
}

// Getter functions
std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickName() const
{
	return (_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}
