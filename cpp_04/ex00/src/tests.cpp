#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void runArgTests(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		Animal *some_animal = new Animal(argv[i]);
		std::cout << "New animal type: " << some_animal->getType() << std::endl;
		some_animal->makeSound();
		delete some_animal;
	}
}

void runTest1(void)
{
	Animal *some_animal;

	// Unspecified Animal
	std::cout << "\n== TEST FOR UNSPECIFIED ANIMAL ==\n" << std::endl;
	some_animal = new Animal();
	std::cout << "New animal type: " << some_animal->getType() << std::endl;
	some_animal->makeSound();
	delete some_animal;

	// Dog
	std::cout << "\n== TEST FOR DOG ==\n" << std::endl;
	some_animal = new Dog();
	std::cout << "New animal type: " << some_animal->getType() << std::endl;
	some_animal->makeSound();
	delete some_animal;
	
	// Cat
	std::cout << "\n== TEST FOR CAT ==\n" << std::endl;
	some_animal = new Cat();
	std::cout << "New animal type: " << some_animal->getType() << std::endl;
	some_animal->makeSound();
	delete some_animal;
}

void run42Test(void)
{
	std::cout << "\n== 42 TEST (pdf) ==\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void run42WrongTest(void)
{
	std::cout << "\n== 42 WRONG TEST ==\n" << std::endl;
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the WrongCat sound!

	delete i;
}
