#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	int_vector	main_chain;
	int_vector	leftovers;

	if (nums.size() / block_size < 2)
		return ;
	stashLeftovers(nums, leftovers, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	restoreLeftovers(nums, leftovers);
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size, 2);
	nums = main_chain;
}

void stashLeftovers(int_vector &nums, int_vector &leftovers, size_t block_size)
{
	if (nums.size() % (block_size * 2))
	{
		leftovers.insert(leftovers.end(), nums.end() - block_size, nums.end());
		nums.erase(nums.end() - block_size, nums.end());
	}
}

void restoreLeftovers(int_vector &nums, int_vector &leftovers)
{
	nums.insert(nums.end(), leftovers.begin(), leftovers.end());
}

void sortSinglePairs(int_vector &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		iv_iterator it = nums.begin() + offset, end = nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > *(it + block_size))
			std::swap_ranges(it - offset, it + 1, it + block_size - offset);
		COMPS++;
	}
};

void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		iv_iterator it = nums.begin() + offset + block_size;
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

/*
	Returns the number of elements to insert based on the given step (starting at 1)
	The mathematical sequence is: 0, 2, 2, 6, 10, 22, 42, etc...
*/
static size_t nextInSequence(size_t step)
{
	return (round((pow(2, step) + pow(-1, step)) / 3));
}

size_t getNumsToInsert(size_t step, const int_vector &nums, size_t block_size)
{
	if (!nums.size())
		return 0;
	if (step <= 1)
		return step;
	size_t next = nextInSequence(step);
		return ((next <= nums.size() / block_size) ? next : nums.size() / block_size);
}


//	===========================================
// INSERTION BLOCK

static size_t calculateInsertionBlockSize(const int_vector &main_chain ,size_t step, size_t block_size)
{
	size_t	size = (pow(2, step) - 1) * block_size;
	return ((size <= main_chain.size()) ? size : main_chain.size());
}

void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size, size_t step)
{
	if (nums.size() == 0)
		return ;
	size_t	to_insert = getNumsToInsert(step, nums, block_size);
	size_t	insertion_block = calculateInsertionBlockSize(main_chain, step, block_size);

	for (iv_iterator position, value; to_insert > 0; --to_insert)
	{
		value = nums.begin() + (to_insert * block_size) - 1;
		position = lowerBound(main_chain.begin(), main_chain.begin() + insertion_block, *value, block_size);
		main_chain.insert(position, value - (block_size -1), value + 1);
	}
	to_insert = getNumsToInsert(step, nums, block_size);
	nums.erase(nums.begin(), nums.begin() + (to_insert * block_size));
	binaryInsert(main_chain, nums, block_size, step + 1);
}

/*
	Iterates over the sorted vector (begin -> end), comparing value to each block-ending value within the vector.
	Returns an iterator to the location of the start of the block at which (block-ending value >= value).
	Does so through a binary search approach (minimal comparisons).
*/
iv_iterator lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size)
{
	iv_iterator middle;
	size_t offset, range_size, half_step;

	offset = block_size - 1;
	range_size = std::distance(begin, end) / block_size;

	while (range_size > 0)
	{
		middle = begin + offset;
		half_step = range_size / 2;
		std::advance(middle, half_step * block_size);
	
		COMPS++;
		if (*middle < value)
		{
			begin = ++middle;
			range_size -= half_step + 1;
		}
		else
			range_size = half_step;
	}
	return begin;
}

// TESTERS
void printVector(int_vector &vec, const std::string &str)
{
	std::cout << "<< "<< str << " >>\n";
	for (iv_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << " | " << *it;
	std::cout << " |" << std::endl;
}
