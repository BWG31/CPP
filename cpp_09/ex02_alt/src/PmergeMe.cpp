#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	// size_t		size = nums.size() / block_size;
	int_vector	main_chain;
	// bool		leftover = false;
	// int 		leftover_value = -1;

	if (nums.size() / 2 <= block_size)
		return baseCase(nums, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size);
}

void baseCase(int_vector &nums, size_t block_size)
{
	if (nums.size() / 2 < block_size)
		return ;
	
	int &first = nums[block_size -1];
	int &second = nums[block_size * 2 - 1];
	if (first > second)
		std::swap(first, second);
}

void sortSinglePairs(int_vector &nums, size_t block_size)
{
	size_t offset = (block_size > 1) ? block_size - 1 : 0;
	for (
		iv_iterator it = nums.begin() + block_size - 1, end = nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > *(it + block_size))
		{
			if (offset)
				std::swap_ranges(it - offset, it + 1, it + block_size - offset);
			else
				std::swap(*it, *(it + block_size));
		}
	}
};

void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	size_t offset = (block_size > 1) ? block_size - 1 : 0;
	iv_iterator first = nums.begin() + block_size - 1;
	main_chain.insert(main_chain.end(), first - offset, first + 1);
	nums.erase(first - offset, first + 1);
	for (
		iv_iterator it = nums.begin() + block_size - 1;
		it < nums.end();
		it += block_size
	)
	{
		main_chain.insert(main_chain.end(), it - offset, it + 1);
		nums.erase(it - offset, it + 1);
		it = nums.begin();
	}
}

void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	size_t offset = (block_size > 1) ? block_size - 1 : 0;
	for (
		iv_iterator it = nums.begin() + block_size - 1;
		it < nums.end();
		it += block_size
	)
	{
		/*
			Bug below: lower_bound is iterating 1 by 1, instead of by last element of block
		*/
		main_chain.insert(std::lower_bound(nums.begin(), nums.end(), *it) - offset, it - offset, it + 1);
		nums.erase(it - offset, it + 1);
		it = nums.begin();
	}
}

// TESTERS
void printVector(int_vector &vec)
{
	std::cout << "<< PRINT VECTOR >>\n";
	for (iv_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << " | " << *it;
	std::cout << " |" << std::endl;
}
