#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Dog: public Animal
{
	protected:
		std::string	type;
	public:
		// Constructors
		Dog(); //default
		Dog(const Dog& other); // copy
		~Dog(); //destructor
		
		Dog&	operator=(const Dog& other); // copy assignment

		// Public Member Functions
		void	makeSound(void) const;
};

# endif
