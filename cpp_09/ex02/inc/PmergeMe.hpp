#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <algorithm>
# include <cmath>
# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <sstream>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define RST	"\033[0m"

template <typename Container>
class PmergeMe
{
	typedef typename Container::iterator Iterator;

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();


		const Container	&getNums() const;
		const Container	&getMainChain() const;

		void mergeInsertionSort(size_t block_size = 1);
		bool isSorted() const;
	
	private:
		Container	_nums;
		Container	_main_chain;

		void	stashLeftovers(Container &leftovers, size_t block_size);
		void	sortSinglePairs(size_t block_size);
		void	restoreLeftovers(Container &leftovers);
		void	constructMainChain(size_t block_size);
		void	binaryInsert(size_t block_size, size_t step = 2);
		size_t	calculateInsertionBlockSize(size_t step, size_t block_size);
		size_t	nextInSequence(size_t step);
		size_t	getNumsToInsert(size_t step, size_t block_size);
		Iterator lowerBound(Iterator begin, Iterator end, int value, size_t block_size);

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);

};

template <typename T>
std::ostream &operator<<(std::ostream &os, const PmergeMe<T> &rhs);

# include "PmergeMe.tpp"

#endif