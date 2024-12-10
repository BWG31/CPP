#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iterator>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <cmath>

# define FIRST_INSERTION_STEP (2)

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;

typedef std::deque<int> int_deq;
typedef int_deq::iterator idq_iterator;

// ==== PmergeMe_list.cpp ====
void PmergeMe(int_deq &nums, size_t block_size = 1);
void sortSinglePairs(int_deq &nums, size_t block_size);
void constructMainChain(int_deq &main_chain, int_deq &nums, size_t block_size);
void binaryInsert(int_deq &main_chain, int_deq &nums, size_t block_size, size_t step);


// ==== PmergeMe_vector.cpp ====
void PmergeMe(int_vector &nums, size_t block_size = 1);
void sortSinglePairs(int_vector &nums, size_t block_size);
void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size);
void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size, size_t step);

// ==== PmergeMe.cpp ====
size_t nextInSequence(const size_t &step);

// ==== TEMPLATE FUNCTIONS ====
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
void restoreLeftovers(T &nums, T &leftovers)
{
	nums.insert(nums.end(), leftovers.begin(), leftovers.end());
};

template <typename T>
size_t calculateInsertionBlockSize(const T &main_chain, const size_t &step, const size_t &block_size)
{
	size_t	size = (pow(2, step) - 1) * block_size;
	return ((size <= main_chain.size()) ? size : main_chain.size());
}

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
}

template <typename T>
void print_container(T &input)
{
	for (typename T::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

#endif