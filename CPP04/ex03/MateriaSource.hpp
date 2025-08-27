#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource: public IMateriaSource
{
	private:
		static const	unsigned int _maxTemplates = 4;
		AMateria*	_knownTemplates[_maxTemplates];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();
		MateriaSource&	operator=(const MateriaSource& other);
		
		void	learnMateria(AMateria* which);
		AMateria*	createMateria(std::string const & type);
		void	printTemplates(void) const;
};

# endif
