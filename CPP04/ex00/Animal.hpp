#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		// Constructors
		Animal(); //default
		Animal(const Animal& other); // copy
		virtual ~Animal(); //destructor
		
		Animal&	operator=(const Animal& other); // copy assignment

		// Member functions
		virtual void	makeSound(void) const;
		const std::string&	getType(void) const;
};

# endif
