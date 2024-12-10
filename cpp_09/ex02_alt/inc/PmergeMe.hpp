#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iterator>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <cmath>
# include <ctime>

# define RED "\033[31m"
# define RST "\033[0m"

# define FIRST_INSERTION_STEP (2)

typedef std::vector<int> int_vector;
typedef std::deque<int> int_deq;

// ==== PmergeMe.cpp ====
bool	validate_input(int_vector &input, int argc, char **argv);
void 	print_timings(double vec_time, size_t vec_size, double deq_time, size_t deq_size);
size_t	nextInSequence(const size_t &step);

// ==== TEMPLATE FUNCTION PROTOTYPES | MAIN HELPERS ====
template <typename T> void print_container(T &input);
template <typename T> double timed_execution(T &input);
template <typename T> int checkSorted(T &sorted, T &copy, const std::string &type);

// ==== TEMPLATE FUNCTION PROTOTYPES | SORTING ALGORITHM ====

template <typename T> void PmergeMe(T &nums, size_t block_size = 1);
template <typename T> void sortSinglePairs(T &nums, size_t block_size);
template <typename T> void constructMainChain(T &main_chain, T &nums, size_t block_size);
template <typename T> void binaryInsert(T &main_chain, T &nums, size_t block_size, size_t step = FIRST_INSERTION_STEP);
template <typename T> void stashLeftovers(T &nums, T &leftovers, const size_t &block_size);
template <typename T> void restoreLeftovers(T &nums, T &leftovers);
template <typename T> size_t calculateInsertionBlockSize(const T &main_chain, const size_t &step, const size_t &block_size);
template <typename T> size_t getNumsToInsert(const size_t &step, const T &nums, const size_t &block_size);
template <typename T> T lowerBound(T begin, T end, const int &value, const size_t &block_size);

// ==== TEMPLATE FUNCTION DEFINITIONS | SORTING ALGORITHM ====

template <typename T>
void PmergeMe(T &nums, size_t block_size)
{
	T	main_chain;
	T	leftovers;

	if (nums.size() / block_size < 2)
		return ;
	stashLeftovers(nums, leftovers, block_size);
	sortSinglePairs(nums, block_size);
	PmergeMe(nums, block_size * 2);
	restoreLeftovers(nums, leftovers);
	constructMainChain(main_chain, nums, block_size);
	binaryInsert(main_chain, nums, block_size);
	nums = main_chain;
};

template <typename T>
void stashLeftovers(T &nums, T &leftovers, const size_t &block_size)
{
	if (nums.size() % (block_size * 2))
	{
		leftovers.insert(leftovers.end(), nums.end() - block_size, nums.end());
		nums.erase(nums.end() - block_size, nums.end());
	}
};

template <typename T>
void sortSinglePairs(T &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		typename T::iterator it = nums.begin() + offset, end = nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > *(it + block_size))
			std::swap_ranges(it - offset, it + 1, it + block_size - offset);
	}
};

template <typename T>
void restoreLeftovers(T &nums, T &leftovers)
{
	nums.insert(nums.end(), leftovers.begin(), leftovers.end());
};

template <typename T>
void constructMainChain(T &main_chain, T &nums, size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		typename T::iterator it = nums.begin() + offset + block_size;
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
};

template <typename T>
void binaryInsert(T &main_chain, T &nums, size_t block_size, size_t step)
{
	if (nums.size() == 0)
		return ;
	size_t	to_insert = getNumsToInsert(step, nums, block_size);
	size_t	insertion_block = calculateInsertionBlockSize(main_chain, step, block_size);

	for (typename T::iterator position, value; to_insert > 0; --to_insert)
	{
		value = nums.begin() + (to_insert * block_size) - 1;
		position = lowerBound(main_chain.begin(), main_chain.begin() + insertion_block, *value, block_size);
		main_chain.insert(position, value - (block_size -1), value + 1);
	}
	to_insert = getNumsToInsert(step, nums, block_size);
	nums.erase(nums.begin(), nums.begin() + (to_insert * block_size));
	binaryInsert(main_chain, nums, block_size, step + 1);
};

template <typename T>
size_t calculateInsertionBlockSize(const T &main_chain, const size_t &step, const size_t &block_size)
{
	size_t	size = (pow(2, step) - 1) * block_size;
	return ((size <= main_chain.size()) ? size : main_chain.size());
};

template <typename T>
size_t getNumsToInsert(const size_t &step, const T &nums, const size_t &block_size)
{
	if (!nums.size())
		return 0;
	if (step <= 1)
		return step;
	size_t next = nextInSequence(step);
		return ((next <= nums.size() / block_size) ? next : nums.size() / block_size);
};

template <typename T>
T lowerBound(T begin, T end, const int &value, const size_t &block_size)
{
	T       middle;
	size_t  range_size, half_step;

	range_size = std::distance(begin, end) / block_size;
	while (range_size > 0)
	{
		middle = begin + block_size - 1;
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
};

// ==== TEMPLATE FUNCTION DEFINITIONS | MAIN HELPERS ====

template <typename T>
void print_container(T &input)
{
	for (typename T::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
};

template <typename T>
int checkSorted(T &sorted, T &copy, const std::string &type)
{
	std::sort(copy.begin(), copy.end());
	if (sorted != copy)
	{
		std::cerr << RED << type << " not sorted\n";
		print_container(sorted);
		std::cerr << RST << std::endl;
		return 1;
	}
	return 0;
};

template <typename T>
double timed_execution(T &input)
{
	std::clock_t start, end;

	start = std::clock();
	PmergeMe(input);
	end = std::clock();

	return (1000.0 * (end - start) / CLOCKS_PER_SEC);
}

#endif