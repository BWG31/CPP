#include "Floor.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

Floor *global_floor;

void test42();
void test1();
void test2();

int main(void)
{
	test42();
	// test1();
	// test2();
	return 0;
}

// CPP_04 PDF 42 TEST
void test42()
{
	global_floor = new Floor(); // Custom Floor to handle dropped objects

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	delete global_floor; // delete any dropped objects (Should be 0)
}

// Test to demonstrate Floor functionality
void test1()
{
	global_floor = new Floor();

	int i;
	IMateriaSource* src = new MateriaSource();
	
	// try to learn 6 >>> last 2 should drop to floor
	for (i = 0; i < 3; i++) {
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	}

	ICharacter* me = new Character("Stan");
	
	// Fill Character Inventory
	for (i = 0; i < 4; i++)
		me->equip(src->createMateria("ice"));
	
	// Should drop to floor as Character full
	me->equip(src->createMateria("cure"));
	
	// Drop _item[0] to floor (should be ice)
	me->unequip(0);

	// Pick up from floor (should be cure)
	me->equip(global_floor->pickUp(1));
	
	ICharacter* greg = new Character("Greg");

	// Item [0] should now be cure
	me->use(0, *greg);

	delete me;
	delete greg;
	delete src;

	delete global_floor;
}

// Custom Test Space
void test2()
{
	global_floor = new Floor();
	
	// ...

	delete global_floor;
}