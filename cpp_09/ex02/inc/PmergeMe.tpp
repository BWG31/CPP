#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS |==========
template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv)
{
	if (argc < 2 || argc > 10001)
		throw std::invalid_argument("Invalid argument count: must be 1 to 10'000");
	for (int i = 1, num = -1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> num) || !iss.eof() || num < 0)
			throw std::invalid_argument("Invalid argument detected");
		_nums.push_back(num);
	}
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container> &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

//  =======| OPERATOR OVERLOADS |=======
template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &rhs)
{
	if (&rhs != this)
	{
		_nums = rhs.getNums();
		_main_chain = rhs.getMainChain();
	}
	return *this;
}

//  ========| GETTERS |=========

template <typename Container>
const Container &PmergeMe<Container>::getNums() const { return _nums; }

template <typename Container>
const Container &PmergeMe<Container>::getMainChain() const { return _main_chain; }

//  ============| METHODS | PUBLIC |=============

template <typename Container>
void PmergeMe<Container>::mergeInsertionSort(size_t block_size)
{
	Container	leftovers;

	if (_nums.size() / block_size < 2)
		return ;
	stashLeftovers(leftovers, block_size);
	sortSinglePairs(block_size);
	mergeInsertionSort(block_size * 2);
	restoreLeftovers(leftovers);
	constructMainChain(block_size);
	binaryInsert(block_size);
	_nums = _main_chain;
	_main_chain.clear();
};

template <typename Container>
bool PmergeMe<Container>::isSorted() const
{
	if (_nums.size() < 2)
		return true;

	bool sorted = true;
	for (typename Container::const_iterator it = _nums.begin() + 1; it < _nums.end(); ++it)
	{
		if (*(it - 1) > *it)
		{
			sorted = false;
			break ;
		}
	}
	return sorted;
};

//  ============| METHODS | PRIVATE |=============

template <typename Container>
void PmergeMe<Container>::stashLeftovers(Container &leftovers, size_t block_size)
{
	if (_nums.size() % (block_size * 2))
	{
		leftovers.insert(leftovers.end(), _nums.end() - block_size, _nums.end());
		_nums.erase(_nums.end() - block_size, _nums.end());
	}
};

template <typename Container>
void PmergeMe<Container>::sortSinglePairs(size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		typename Container::iterator it = _nums.begin() + offset, end = _nums.end();
		it < end - block_size;
		it += block_size * 2
	)
	{
		if (*it > *(it + block_size))
			std::swap_ranges(it - offset, it + 1, it + block_size - offset);
	}
};

template <typename Container>
void PmergeMe<Container>::restoreLeftovers(Container &leftovers)
{
	_nums.insert(_nums.end(), leftovers.begin(), leftovers.end());
};

template <typename Container>
void PmergeMe<Container>::constructMainChain(size_t block_size)
{
	size_t offset = block_size - 1;
	for (
		typename Container::iterator it = _nums.begin() + offset + block_size;
		it < _nums.end();
		it += block_size
	)
	{
		_main_chain.insert(_main_chain.end(), it - offset, it + 1);
		size_t tmp = it - _nums.begin();
		_nums.erase(it - offset, it + 1);
		it = _nums.begin() + tmp;
	}
	_main_chain.insert(_main_chain.begin(), _nums.begin(), _nums.begin() + block_size);
	_nums.erase(_nums.begin(), _nums.begin() + block_size);
};

template <typename Container>
void PmergeMe<Container>::binaryInsert(size_t block_size, size_t step)
{
	if (_nums.size() == 0)
		return ;
	size_t	to_insert = getNumsToInsert(step, block_size);
	size_t	insertion_block = calculateInsertionBlockSize(step, block_size);

	for (typename Container::iterator position, value; to_insert > 0; --to_insert)
	{
		value = _nums.begin() + (to_insert * block_size) - 1;
		position = lowerBound(_main_chain.begin(), _main_chain.begin() + insertion_block, *value, block_size);
		_main_chain.insert(position, value - (block_size -1), value + 1);
	}
	to_insert = getNumsToInsert(step, block_size);
	_nums.erase(_nums.begin(), _nums.begin() + (to_insert * block_size));
	binaryInsert(block_size, step + 1);
};

template <typename Container>
size_t PmergeMe<Container>::calculateInsertionBlockSize(size_t step, size_t block_size)
{
	size_t	size = (pow(2, step) - 1) * block_size;
	return ((size <= _main_chain.size()) ? size : _main_chain.size());
};

/*
	Returns the number of elements to insert based on the given step (starting at 1)
	The mathematical sequence is: 0, 2, 2, 6, 10, 22, 42, etc...
*/
template <typename Container>
size_t PmergeMe<Container>::nextInSequence(size_t step)
{
	return (round((pow(2, step) + pow(-1, step)) / 3));
}

template <typename Container>
size_t PmergeMe<Container>::getNumsToInsert(size_t step, size_t block_size)
{
	if (!_nums.size())
		return 0;
	if (step <= 1)
		return step;
	size_t next = nextInSequence(step);
		return ((next <= _nums.size() / block_size) ? next : _nums.size() / block_size);
};

template <typename Container>
typename Container::iterator PmergeMe<Container>::lowerBound(Iterator begin, Iterator end, int value, size_t block_size)
{
	Iterator       middle;
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

//  ========| NON MEMBER |=========
template <typename T>
std::ostream &operator<<(std::ostream &os, const PmergeMe<T> &rhs)
{
	for (size_t i = 0; i < rhs.getNums().size(); ++i)
		os << ' ' << rhs.getNums()[i];
	os << std::endl;
	return os;
}


#endif