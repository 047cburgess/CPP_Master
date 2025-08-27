#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		// Constructors
		WrongCat(); //default
		WrongCat(const WrongCat& other); // copy
		~WrongCat(); //destructor
		
		WrongCat&	operator=(const WrongCat& other); // copy assignment
		void	makeSound() const;

};

# endif
