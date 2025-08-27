#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "--SUBJECT TEST--" << std::endl;
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "--Making copy of Materia src original--" << std::endl;
	MateriaSource copyMateriaSource(*src);
	copyMateriaSource.printTemplates();

	src->learnMateria(new Cure());

	std::cout << "--Printing Materia src original--" << std::endl;
	src->printTemplates();
	std::cout << "--Printing Materia deep copy--" << std::endl;
	copyMateriaSource.printTemplates();

	std::cout << "--Making copy of Materia copy--" << std::endl;
	MateriaSource copyofcopy = copyMateriaSource;
	copyofcopy.printTemplates();

	std::cout << "--adding Ice to copy Materia-- " << std::endl;
	copyMateriaSource.learnMateria(new Ice());
	copyMateriaSource.printTemplates();
	std::cout << "--printing copy of copy to show it hasnt changed--" << std::endl;
	copyofcopy.printTemplates();

	AMateria* noroom = new Cure();
	src->learnMateria(noroom); // too many materia
	delete noroom;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	AMateria * tmp3 = src->createMateria("cure");
	me->equip(tmp3);
	
	tmp = src->createMateria("notvalidMateria"); // not valid template
	tmp = src->createMateria("ice");
	me->equip(tmp); // could not equipe me, inventory fll
	me->unequip(3); // delete index 3
	delete tmp3;
	me->equip(tmp); // now works


	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob); // out of range
	delete bob;
	delete me;
	delete src;

	std::cout << "--Test for passing NULL pointers---" << std::endl;
	MateriaSource src1;
	AMateria* null_ice = NULL;
	src1.learnMateria(null_ice);
	Character casey("Casey");
	casey.equip(null_ice);


	std::cout << "--Test for clone function--" << std::endl;
	AMateria* original = new Ice();
	std::cout << "original type: " << original->getType() << std::endl;
	std::cout << "addr original: " << original << std::endl;
	AMateria* copy = original->clone();
	delete original;
	std::cout << "clone type: " << copy->getType() << std::endl;
	std::cout << "addr clone: " << copy << std::endl;
	delete copy;


	return 0;

}
