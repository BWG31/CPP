#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	size_t		size = nums.size() / block_size;
	int_vector	main_chain;
	bool		leftover = false;
	int 		leftover_value = -1;

	// Base case
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size);
}

void sortSinglePairs(int_vector &nums, size_t block_size)
{
	for (
		iv_iterator it = nums.begin() + block_size - 1, end = nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > (*it + block_size))
			std::swap_ranges(it, it + block_size -1, it + block_size);
	}
};

void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	iv_iterator first = nums.begin() + block_size - 1;
	main_chain.insert(main_chain.end(), first, first + block_size - 1);
	nums.erase(first, first + block_size - 1);
	for (
		iv_iterator it = nums.begin();
		it < nums.end();
		it += block_size
	)
	{
		main_chain.insert(main_chain.end(), it, it + block_size - 1);
		nums.erase(it, it + block_size - 1);
		it = nums.begin();
	}
}

void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	// for ()
}

// TESTERS
void printVector(int_vector &vec)
{
	std::cout << "<< PRINT VECTOR >>\n";
	for (iv_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << " | " << *it;
	std::cout << " |" << std::endl;
}
