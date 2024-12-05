#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	int_vector	main_chain;
	int_vector	leftovers;

	if (nums.size() / 2 <= block_size)
		return (baseCase(nums, block_size));
	stashLeftovers(nums, leftovers, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	restoreLeftovers(nums, leftovers);
	constructMainChain(main_chain, nums, block_size);
	binaryInsertRec(main_chain, nums, block_size, 2);
	nums = main_chain;
	std::cout << " || End of func ||\n";
	printVector(nums, "nums");
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

void baseCase(int_vector &nums, size_t block_size)
{
	if (nums.size() / 2 < block_size)
		return ;

	size_t offset = block_size - 1;
	iv_iterator first = nums.begin() + offset;
	iv_iterator second = first + block_size;
	if (*first > *second)
		std::swap_ranges(first - offset, first + 1, second - offset);
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
		main_chain.insert(main_chain.end(), it - offset, it + 1); //Invalidates main_chain iterators (if realloc required)
		size_t tmp = it - nums.begin();
		nums.erase(it - offset, it + 1); // Invalidates iterators
		it = nums.begin() + tmp;
	}
	main_chain.insert(main_chain.begin(), nums.begin(), nums.begin() + block_size);
	nums.erase(nums.begin(), nums.begin() + block_size);
}

void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	size_t n, m;
	iv_iterator position;

	for (n = 0, m = 0; n < nums.size(); n += block_size, m += 2 * block_size)
	{
		position = lowerBound(main_chain.begin(), main_chain.begin() + m, nums[n + offset], block_size);
		main_chain.insert(position, nums.begin() + n, nums.begin() + (n + block_size));
	}
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



void binaryInsertRec(int_vector &main_chain, int_vector &nums, size_t block_size, size_t step)
{
	std::cout << "\n\n[[[[ NEW FUNCTION ]]]] ------------------------------------------\n\n";
	printVector(main_chain, "main_chain");
	printVector(nums, "nums");
	std::cout << "block_size = " << block_size << "\t\tstep = " << step << std::endl;
	std::cout << "-------------------\n";
	if (nums.size() == 0)
		return ;
	size_t	offset = block_size - 1;
	size_t	inserted = (main_chain.size() < nums.size()) ? 0 : main_chain.size() - nums.size();
	size_t	to_insert = getNumsToInsert(step, nums, block_size);
	size_t	n = to_insert * block_size - 1;

	// NOTACCOUNTING FOR LEFTOVERS (INBALANCE BETWEEN .size())
	for (iv_iterator position, value, comp_end; to_insert > 0; --to_insert)
	{
		value = nums.begin() + n;
		std::cout << "\n\t\t{{ NEW ITERATION }}\n\nn: " << n << "\tinserted: " << inserted << "\tto_insert: " << to_insert << std::endl;
		if (std::distance(value, nums.end() - 1) == 0)
			comp_end = main_chain.end();
		else
			comp_end = main_chain.begin() + n + inserted + block_size;
		std::cout << "___\nSearching for [" << *value << "] with end after [" << *(comp_end - 1) << "] in\n";
		printVector(main_chain, "main_chain");
		std::cout << "___" << std::endl;
		position = lowerBound(main_chain.begin(), comp_end, *value, block_size);
		std::cout << "Inserting: " << *value << " before " << *position << '\n';
		main_chain.insert(position, value - offset, value + 1);
		// nums.erase(value - offset, value + 1);
		n -= block_size;
		inserted += block_size;
	}
	std::cout << "Erasing nums\n";
	printVector(nums, "nums");
	to_insert = getNumsToInsert(step, nums, block_size);
	nums.erase(nums.begin(), nums.begin() + (to_insert * block_size));
	printVector(nums, "nums");
	std::cout << "nums erased\n";
	printVector(main_chain, "main_chain");
	binaryInsertRec(main_chain, nums, block_size, step + 1);
}

// ============================================


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
