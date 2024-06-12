#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void runTest1(void);
void runTest2(char *animal_count);

/*
	./brain 									>>> runTest1()
	./brain <number of Animals> (50%dog 50%cat)	>>> runTest2()
*/

int main(int argc, char **argv)
{
	if (argc != 2)
		runTest1();
	else
		runTest2(argv[1]);
	return (0);
}
