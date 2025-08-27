#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (unsigned int i = 0; i < _maxTemplates; i++)
		this->_knownTemplates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (unsigned int i = 0; i < _maxTemplates; i++)
		this->_knownTemplates[i] = NULL;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource & other)
{
	if (this != &other)
	{
		// delete existing knownTemplates and copy other one
		for (unsigned int i = 0; i < _maxTemplates; i++)
		{
			if (this->_knownTemplates[i] != NULL)
			{
				delete (this->_knownTemplates[i]);
				this->_knownTemplates[i] = NULL;
			}
			if (other._knownTemplates[i] != NULL)
				this->_knownTemplates[i] = other._knownTemplates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (unsigned int i = 0; i < _maxTemplates; i++)
		delete this->_knownTemplates[i];
}

void	MateriaSource::learnMateria(AMateria* what)
{
	if (what == NULL)
	{
		std::cerr << "Could not learn materia as value passed is null" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < _maxTemplates; i++)
	{
		if (this->_knownTemplates[i] == NULL)
		{
			std::cout << "Added template for " << what->getType() << std::endl;
			this->_knownTemplates[i] = what;
			return ;
		}
	}
	std::cerr << "Could not learn materia as templates are full." << what->getType() << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{

	for (unsigned int i = 0; i < _maxTemplates; i++)
	{
		if (this->_knownTemplates[i] && (this->_knownTemplates[i]->getType() == type))
		{
			return (this->_knownTemplates[i]->clone());
		}
	}
	std::cerr << "Could not find template : " << type << std::endl;
	return (0);
}

void	MateriaSource::printTemplates() const
{
	std::cout << "Contents of MateriaSource-" << std::endl;
	for (unsigned int i = 0; i < _maxTemplates; i++)
	{
		if (this->_knownTemplates[i] != NULL)
		{
			std::cout << i << ": " << this->_knownTemplates[i]->getType() << std::endl;
		}
		else
			std::cout << i << ": NULL" << std::endl; 
	}
}
