#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class	AAnimal
{
	protected:
		std::string	type;
	public:
		// Constructors
		AAnimal(); //default
		AAnimal(const AAnimal& other); // copy
		virtual ~AAnimal(); //destructor
		
		AAnimal&	operator=(const AAnimal& other); // copy assignment

		// Member functions
		virtual void	makeSound(void) const = 0;
		const std::string&	getType(void) const;
};

# endif
