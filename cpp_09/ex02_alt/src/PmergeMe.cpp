#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	int_vector	main_chain;
	int_vector	leftovers;

	if (nums.size() / 2 <= block_size)
		return baseCase(nums, block_size);
	if (nums.size() % (block_size * 2))
	{
		leftovers.insert(leftovers.end(), nums.end() - block_size, nums.end());
		nums.erase(nums.end() - block_size, nums.end());
	}
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	nums.insert(nums.end(), leftovers.begin(), leftovers.end());
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size);
	nums = main_chain;
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
}

// void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size)
// {
// 	size_t offset = block_size - 1;
// 	iv_iterator it, main_begin, position, paired_element;
// 	for (
// 		it = nums.begin(), main_begin = main_chain.begin();
// 		it + offset < nums.end();
// 		it += block_size
// 	)
// 	{
// 		main_begin = main_chain.begin(); // This gets corrupted if an insertion happens at the start during prior iteration
// 		paired_element = main_begin + std::distance(nums.begin(), it);
// 		position = lowerBound(main_begin, paired_element, *(it + offset), block_size);
// 		main_chain.insert(position, it, it + block_size);
// 	}
// }

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
void printVector(int_vector &vec)
{
	std::cout << "<< PRINT VECTOR >>\n";
	for (iv_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << " | " << *it;
	std::cout << " |" << std::endl;
}
