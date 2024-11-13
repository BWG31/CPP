#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

Base *generate(void);

int main(void)
{
	Base *ptr = generate();
	delete ptr;
	return (0);
}

Base *generate(void)
{
	Base *ptr;

	srand(time(NULL) + getpid());
	int num = rand() % 3;
	switch (num){
		case 0:
			ptr = new A;
			break ;
		case 1:
			ptr = new B;
			break ;
		case 2:
			ptr = new C;
			break ;
		default:
			ptr = NULL;
	}
	std::cout << "num: " << num << std::endl;
	return (ptr);
}
