#include "Character.hpp"

// Default constructor
Character::Character(void)
{
	return ;
}

Character::Character(std::string name): _name(name)
{
	for (unsigned int i = 0; i < _inventoryMax; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	*this = other;
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other.getName();

		// delete existing inventory and copy other one
		for (unsigned int i = 0; i < _inventoryMax; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete (this->_inventory[i]);
				this->_inventory[i] = NULL;
			}
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	for (unsigned int i = 0; i < _inventoryMax; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}

	}
	return;
}

const std::string& Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << "ERROR: Could not equip " << this->_name << " : Materia is NULL" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < _inventoryMax; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Equipped " << this->getName() << " with " << m->getType() << " at index " << i << std::endl;
			return;
		}
	}
	std::cerr << "ERROR: Could not equip " << this->_name << " : Materia inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if ((unsigned int)idx >= _inventoryMax)
	{
		std::cerr << "Could not unequip " << this->_name << " : invalid inventory index." << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cerr << "Could not unequip " << this->_name << " : nothing at this index." << std::endl;
		return ;
	}
	std::cout << "Unequipped " << this->getName() << " from " << this->_inventory[idx]->getType() << " index " << idx << std::endl;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if ((unsigned int)idx >= _inventoryMax)
	{
		std::cerr << idx << ": index of Materia is out of range, couldn't use it." << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cerr << idx << ": no Materia found at this index" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

