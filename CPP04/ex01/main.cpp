#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	// ANIMAL
	std::cout << "-- ANIMAL/ANIMAL --" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;

	// DOG
	std::cout << "-- ANIMAL/MALLOC DOGGIE --" << std::endl;
	const Animal* j = new Dog();
	std::cout << "type: " << j->getType() << " " << std::endl;
	j->makeSound(); // dog
	delete j;

	// DOG
	std::cout << "-- STACK DOGGIE --" << std::endl;
	const Dog mydoggie;
	std::cout << "type: " << mydoggie.getType() << " " << std::endl;
	mydoggie.makeSound(); // dog
	
	// DOG
	std::cout << "-- COPY STACK DOGGIE --" << std::endl;
	const Dog copydoggie(mydoggie);
	std::cout << "type: " << copydoggie.getType() << " " << std::endl;
	copydoggie.makeSound(); // dog

	// CAT
	std::cout << "-- ANIMAL/MALLOC CAT --" << std::endl;
	const Animal* i = new Cat();
	std::cout << "type: " << i->getType() << " " << std::endl;
	i->makeSound(); // cat
	delete i;

	// WRONG ANIMAL
	std::cout << "-- WRONGANIMAL/MALLOC WRONGCAT --" << std::endl;
	const WrongAnimal* a = new WrongCat();
	std::cout << "type: " << a->getType() << " " << std::endl;
	a->makeSound(); // wrong animal sound
	delete a;

}
