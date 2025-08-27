#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	private:
		Brain*	brain;
	public:
		// Constructors
		Dog(); //default
		Dog(const Dog& other); // copy
		~Dog(); //destructor
		
		Dog&	operator=(const Dog& other); // copy assignment

		// Public Member Functions
		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

# endif
