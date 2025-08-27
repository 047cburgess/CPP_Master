#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog: public AAnimal
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
