#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

#include "easyfind.hpp"

template <typename Container> void print_container(const Container &container);
void test_vector(void);
void test_list(void);
void test_deque(void);
void test_const_list(void);

int main(void)
{
	test_vector();
	test_list();
	test_deque();
	test_const_list();
	return 0;
}

void test_vector(void)
{
	std::cout << "== VECTOR TEST ==\n";

	std::vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(42);
	v.push_back(100);
	v.push_back(6);
	print_container(v);

	std::vector<int>::iterator it = easyfind(v, 42);
	if (it != v.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Unable to find" << std::endl;
}

void test_list(void)
{
	std::cout << "== LIST TEST ==\n";

	std::list<int> lst;
	lst.push_back(-5);
	lst.push_back(5);
	lst.push_back(-2);
	lst.push_back(2);
	lst.push_back(100);
	print_container(lst);

	std::list<int>::iterator it = easyfind(lst, 42);
	if (it != lst.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Unable to find" << std::endl;
}

void test_deque(void)
{
	std::cout << "== DEQUE TEST ==\n";

	std::deque<int> deq;
	deq.push_back(-2);
	deq.push_back(-1);
	deq.push_back(0);
	deq.push_back(1);
	deq.push_back(42);
	print_container(deq);

	std::deque<int>::iterator it = easyfind(deq, 42);
	if (it != deq.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Unable to find" << std::endl;
}

void test_const_list(void)
{
	std::cout << "== CONST LIST TEST ==\n";

	int arr[] = {1, 5, 0, 42, 100, 6};

	const std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_container(lst);

	std::list<int>::const_iterator it = easyfind(lst, 42);
	if (it != lst.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Unable to find" << std::endl;
}

template <typename T>
void print_container(const T &container)
{
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}
