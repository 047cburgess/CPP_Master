#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class	Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact(void); // Constructor
		~Contact(void); // Destructor
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		void	setFirstName(const std::string &value);
		void	setLastName(const std::string &value);
		void	setNickName(const std::string &value);
		void	setPhoneNumber(const std::string &value);
		void	setDarkestSecret(const std::string &value);
};
#endif
