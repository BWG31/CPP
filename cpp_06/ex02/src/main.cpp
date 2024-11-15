#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

Base	*generate(void);
void	identify(Base *p);
void 	identify(Base &p);
void	print_identity(const char c);

int main(void)
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
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

void identify(Base *p)
{
	Base *tmp = NULL;

	tmp = dynamic_cast<A*>(p);
	if (tmp)
		return (print_identity('A'));
	tmp = dynamic_cast<B*>(p);
	if (tmp)
		return (print_identity('B'));
	tmp = dynamic_cast<C*>(p);
	if (tmp)
		return (print_identity('C'));
	return (print_identity(0));
}

void identify(Base &p)
{
	try{
		(void)dynamic_cast<A&>(p);
		print_identity('A');
	} catch (...){
		try{
			(void)dynamic_cast<B&>(p);
			return (print_identity('B'));
		} catch (...){
			try{
				(void)dynamic_cast<C&>(p);
				return (print_identity('C'));
			} catch (...){
				return (print_identity(0));
			}
		}
	}
}

void print_identity(const char c)
{
	if (c == 0)
		std::cout << "Could not find identity" << std::endl;
	else
		std::cout << "Result: " << c << std::endl;
}
