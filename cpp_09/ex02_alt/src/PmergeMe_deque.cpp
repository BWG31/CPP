#include "PmergeMe.hpp"

void PmergeMe(int_deq &nums, size_t block_size)
{
	int_deq	main_chain;
	int_deq	leftovers;

	if (nums.size() / block_size < 2)
		return ;
	stashLeftovers(nums, leftovers, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	restoreLeftovers(nums, leftovers);
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size, FIRST_INSERTION_STEP);
	nums = main_chain;
}

static idq_iterator move_it(const idq_iterator &it, int i)
{
	idq_iterator tmp(it);

	std::advance(tmp, i);
	return tmp;
}

void sortSinglePairs(int_deq &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		idq_iterator it = nums.begin() + offset, end = nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > *(move_it(it, block_size)))
			std::swap_ranges(it - offset, it + 1, it + block_size - offset);
	}
}

void constructMainChain(int_deq &main_chain, int_deq &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		idq_iterator it = nums.begin() + offset + block_size;
		it < nums.end();
		it += block_size
	)
	{
		main_chain.insert(main_chain.end(), it - offset, it + 1);
		size_t tmp = it - nums.begin();
		nums.erase(it - offset, it + 1);
		it = nums.begin() + tmp;
	}
	main_chain.insert(main_chain.begin(), nums.begin(), nums.begin() + block_size);
	nums.erase(nums.begin(), nums.begin() + block_size);
}

void binaryInsert(int_deq &main_chain, int_deq &nums, size_t block_size, size_t step)
{
	if (nums.size() == 0)
		return ;
	size_t	to_insert = getNumsToInsert(step, nums, block_size);
	size_t	insertion_block = calculateInsertionBlockSize(main_chain, step, block_size);

	for (idq_iterator position, value; to_insert > 0; --to_insert)
	{
		value = nums.begin() + (to_insert * block_size) - 1;
		position = lowerBound(main_chain.begin(), main_chain.begin() + insertion_block, *value, block_size);
		main_chain.insert(position, value - (block_size -1), value + 1);
	}
	to_insert = getNumsToInsert(step, nums, block_size);
	nums.erase(nums.begin(), nums.begin() + (to_insert * block_size));
	binaryInsert(main_chain, nums, block_size, step + 1);
}
