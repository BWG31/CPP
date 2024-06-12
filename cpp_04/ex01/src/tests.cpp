#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

bool validArgument(char *animal_count);

void runTest1(void)
{
	std::cout << "\n== TEST1 (DEFAULT) ==\n" << std::endl;
	
	Dog *dog1 = new Dog(); // Allocate memory for dog1 (default constructor)
	
	// Add ideas to Dog Brain
	dog1->newIdea("Walk");
	dog1->newIdea("Fetch");
	dog1->newIdea("Play");

	// Overflow Dog Brain
	for (int i = 0; i < 98; i++)
		dog1->newIdea("Woof");

	Dog *dog2 = new Dog(*dog1); // Allocate memory for dog2 (copy constructor)

	delete dog1; // Free memory allocated for dog1

	dog2->printIdeas(); // dog2 should still be useable
	delete dog2;
}

void runTest2(char *animal_count)
{
	if (!validArgument(animal_count))
	{
		std::cout << RED << "Invalid argument" << RESET << std::endl;
		return ;
	}

	int num_animals = std::atoi(animal_count);

	// Create animal array (50% Dog, 50% Cat)
	Animal *animals[num_animals];
	for (int i = 0; i < num_animals; i++)
	{
		if (i < num_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	// All animals make sound
	for (int i = 0; i < num_animals; i++)
		animals[i]->makeSound();
	
	// Delete animals
	for (int i = 0; i < num_animals; i++)
		delete animals[i];
}

bool validArgument(char *animal_count)
{
	if (*animal_count == '\0')
		return false;
	for (int i = 0; animal_count[i]; i++)
	{
		if (animal_count[i] && !isdigit(animal_count[i]))
			return false;
	}
	int num_animals = std::atoi(animal_count);
	if (num_animals <= 0 || num_animals > 100000) // Hard limit to avoid stack overflow
		return false;
	return true;
}
