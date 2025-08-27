#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character: public ICharacter
{
	private:
		Character();
		std::string	_name;
		AMateria* _inventory[4];
		static const unsigned int _inventoryMax = 4;

	public:
		Character(std::string name);
		Character(const Character& other);
		~Character();
		Character&	operator=(const Character& other);

		void	use(int idx, ICharacter& target);
		void equip(AMateria* m);
		void unequip(int idx);
		const std::string& getName() const;
};
# endif
