// SUBJECT REQUIREMENT
#include "iter.hpp"

// TESTING HELPERS
#include "increment.hpp"
#include "print_array.hpp"
#include <iostream>
#include <string>

	void int_test();
	void char_test();
	void double_test();
	void string_test();

int main(void)
{
	int_test();
	char_test();
	double_test();
	string_test();
	return (0);
}

void int_test()
{
	int	numbers[] = {1, 2, 3, 4, 5};
	int length = sizeof(numbers) / sizeof(*numbers);

	print_array(numbers, length);
	iter(numbers, length, increment);
	print_array(numbers, length);
}

void char_test()
{
	char	letters[] = "0123456789";
	int 	length = sizeof(letters) - 1;

	print_array(letters, length);
	iter(letters, length, increment);
	print_array(letters, length);
}

void double_test()
{
	double	numbers[] = {0.0, 1.1, 2.2};
	int 	length = sizeof(numbers) / sizeof(*numbers);

	print_array(numbers, length);
	iter(numbers, length, increment);
	print_array(numbers, length);
}

void string_test()
{
	std::string words[] = {"Hello", "my", "name", "is", "Ben"};
	int			length = sizeof(words) / sizeof(*words);

	print_array(words, length);
	iter(words, length, increment);
	print_array(words, length);
}
