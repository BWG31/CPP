#include "PmergeMe.hpp"

void PmergeMe(int_vector &nums, size_t block_size)
{
	int_vector	main_chain;

	if (nums.size() / 2 <= block_size)
		return baseCase(nums, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
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

void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		iv_iterator it = nums.begin(), position, main_begin, paired_element;
		it + offset < nums.end();
		it += block_size
	)
	{
		main_begin = main_chain.begin();
		paired_element = main_begin + std::distance(nums.begin(), it);
		position = lowerBound(main_begin, paired_element, *(it + offset), block_size);
		main_chain.insert(position, it, it + block_size);
	}
}

// LOWER_BOUND
template<class ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type,
         class Compare>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step);
 
        if (comp(*it, value))
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
 
    return first;
}

/*
	Iterates over the sorted vector (begin -> end), comparing value to each block-ending value within the vector.
	Returns the index location of the start of the block at which (block-ending value >= value).
	Does so through a binary search approach (minimal comparisons).
*/
size_t lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size)
{

}

// TESTERS
void printVector(int_vector &vec)
{
	std::cout << "<< PRINT VECTOR >>\n";
	for (iv_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << " | " << *it;
	std::cout << " |" << std::endl;
}
