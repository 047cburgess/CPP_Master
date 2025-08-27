#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		// Constructors
		WrongAnimal(); //default
		WrongAnimal(const WrongAnimal& other); // copy
		virtual ~WrongAnimal(); //destructor
		
		WrongAnimal&	operator=(const WrongAnimal& other); // copy assignment

		// Member functions
		void	makeSound(void) const;
		const std::string&	getType(void) const;
};

# endif
