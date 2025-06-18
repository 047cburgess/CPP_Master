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
	std::cout << "sound: "; 
	meta->makeSound();
	delete meta;

	// DOG
	std::cout << "-- ANIMAL/MALLOC DOGGIE --" << std::endl;
	const Animal* j = new Dog();
	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "sound: ";
	j->makeSound(); // dog
	delete j;

	// DOG
	std::cout << "-- STACK DOGGIE --" << std::endl;
	const Dog mydoggie;
	std::cout << "type: " << mydoggie.getType() << " " << std::endl;
	std::cout << "sound: ";
	mydoggie.makeSound(); // dog
	
	// DOG
	std::cout << "-- COPY STACK DOGGIE --" << std::endl;
	const Dog copydoggie(mydoggie);
	std::cout << "type: " << copydoggie.getType() << " " << std::endl;
	std::cout << "sound: ";
	copydoggie.makeSound(); // dog

	// CAT
	std::cout << "-- ANIMAL/MALLOC CAT --" << std::endl;
	const Animal* i = new Cat();
	std::cout << "type: " << i->getType() << " " << std::endl;
	std::cout << "sound: ";
	i->makeSound(); // cat
	delete i;

	// WRONG ANIMAL
	std::cout << "-- WRONGANIMAL/MALLOC WRONGCAT --" << std::endl;
	const WrongAnimal* a = new WrongCat();
	std::cout << "type: " << a->getType() << " " << std::endl;
	std::cout << "sound: ";
	a->makeSound(); // wrong animal sound
	delete a;

	// EX01
	std::cout << "--TESTING EX01--" << std::endl;
	std::cout << "Creating array of 10 pointers to animals" << std::endl;
	Animal* myPets[10];
	std::cout << "Creating 5 dogs in the array" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "[" << i + 1<< "] ";
		myPets[i] = new Dog();

	}

	std::cout << "Creating 5 cats in the array" << std::endl;
	for (int i = 5; i < 10; i++)
	{
		std::cout << "[" << i + 1<< "] ";
		myPets[i] = new Cat();
	}


	// TESTING DEEEP VS SHALLOW COPY
	std::cout << "---TESTING DEEP VS SHALLOW COPY---" << std::endl;
	Animal* puppy = myPets[0];
	std::cout << "puppy type: " << puppy->getType() << std::endl;
	std::cout << "mypets[0] type: " << myPets[0]->getType() << std::endl;

	




	std::cout << "---DELETING MYPETS---" << std::endl;
	for (int i = 0; i < 10; i++)
		delete myPets[i];
}
