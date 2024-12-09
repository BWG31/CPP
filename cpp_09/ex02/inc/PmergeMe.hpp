#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <algorithm>
# include <cmath>
# include <iostream>
# include <iomanip>

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;

class PmergeMe
{
	public:
		PmergeMe(const int_vector &input);
		~PmergeMe();
	
		void	mergeInsertionSort(size_t block_size = 1);

		const int_vector	&getNums() const;
		const size_t		&getComparisons() const;

	private:
		int_vector	_nums;
		int_vector	_main_chain;
		size_t		_comparisons;

		void stashLeftovers(int_vector &leftovers, const size_t &block_size);
		void popLeftovers(int_vector &leftovers);
		void sortSinglePairs(const size_t &block_size);
		void constructMainChain(const size_t &block_size);
		void binaryInsert(const size_t &block_size, const size_t &step = 2);
		size_t nextInSequence(const size_t &step);
		size_t getNumsToInsert(const size_t &step, const size_t &block_size);
		size_t getInsertionBlockSize(const size_t &step, const size_t &block_size);
		iv_iterator lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size);

	// Unused coplien elements
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs);

#endif