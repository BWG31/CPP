#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void runArgTests(int argc, char **argv);
void runTest1(void);
void run42Test(void);
void run42WrongTest(void);

/*
	./animal 			>>> run42Test()
	./animal wrong		>>> run42WrongTest()
	./animal test1		>>> runTest1()
	./animal args...	>>> runArgTests()  >>>  Runs generic test for each argument
*/

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!strcmp(argv[1], "test1"))
			runTest1();
		else if (!strcmp(argv[1], "wrong"))
			run42WrongTest();
		else
			runArgTests(argc, argv);
	}
	else
		run42Test();
	return (0);
}