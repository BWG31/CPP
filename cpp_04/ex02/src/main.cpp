#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main(void)
{
	AAnimal *animal1 = new Dog();

	// AAnimal *animal2 = new AAnimal(); // THIS SHOULD CAUSE AN ERROR

	delete animal1;
	return (0);
}
