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

	std::cout << "---DELETING MYPETS---" << std::endl;
	for (int i = 0; i < 10; i++)
		delete myPets[i];


	// TESTING DEEEP VS SHALLOW COPY
	std::cout << "---TESTING DEEP VS SHALLOW COPY---" << std::endl;
	std::cout << "Creating Dog labrador" << std::endl;
	Dog labrador;
	labrador.getBrain()->setIdea(0, "labrador idea 0");

	std::cout << "Dog frenchie = labrador (copy assignment)" << std::endl;
	Dog frenchie = labrador;

	std::cout << "labrador type: " << labrador.getType() << std::endl;
	std::cout << "frenchie type: " << frenchie.getType() << std::endl;
	std::cout << "labrador ideas[0]: " << labrador.getBrain()->getIdea(0) << std::endl;
	std::cout << "frenchie ideas[0]: " << frenchie.getBrain()->getIdea(0) << std::endl;


	std::cout << "setting labrador ideas[0] to 'new lab idea 0'" << std::endl;
	labrador.getBrain()->setIdea(0, "new lab idea 0");
	std::cout << "labrador ideas[0]: " << labrador.getBrain()->getIdea(0) << std::endl;
	std::cout << "frenchie ideas[0]: " << frenchie.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "Testing leaks for copy reassignment. frenchie = newDog" << std::endl;
	Dog newDog;
	frenchie = newDog;

	std::cout << "Testing Copy Constructor. copyLabrador(labrador)" << std::endl;
	Dog copyLabrador(labrador);
	std::cout << "labrador ideas[0]: " << labrador.getBrain()->getIdea(0) << std::endl;
	std::cout << "copyLabrador ideas[0]: " << copyLabrador.getBrain()->getIdea(0) << std::endl;

	std::cout << "setting labrador ideas[0] to 'another lab idea 0'" << std::endl;
	labrador.getBrain()->setIdea(0, "another lab idea 0");
	std::cout << "labrador ideas[0]: " << labrador.getBrain()->getIdea(0) << std::endl;
	std::cout << "copylabrador ideas[0]: " << copyLabrador.getBrain()->getIdea(0) << std::endl;

	std::cout << "setting copyLabrador ideas[0] to 'here's my copy lab idea 0'" << std::endl;
	copyLabrador.getBrain()->setIdea(0, "here's my copy lab idea 0");
	std::cout << "labrador ideas[0]: " << labrador.getBrain()->getIdea(0) << std::endl;
	std::cout << "copylabrador ideas[0]: " << copyLabrador.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "END OF MAIN" << std::endl;

}
