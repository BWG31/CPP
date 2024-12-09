#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS |==========
PmergeMe::PmergeMe()
{
	std::cerr << "Default constructor should not be used" << std::endl;
}

PmergeMe::PmergeMe(const int_vector &input) :
	_nums(input),
	_comparisons(0)
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
PmergeMe::~PmergeMe() {}

//  =======| OPERATOR OVERLOADS |=======
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (&rhs != this)
	{
		_nums = rhs.getNums();
		_comparisons = rhs.getComparisons();
	}
	return *this;
}

//  ============| METHODS |=============

void PmergeMe::mergeInsertionSort(size_t block_size)
{
	int_vector	leftovers;

	if (_nums.size() / block_size < 2)
		return ;
	stashLeftovers(leftovers, block_size);
	sortSinglePairs(block_size);
	mergeInsertionSort(block_size * 2);
	popLeftovers(leftovers);
	constructMainChain(block_size);
	binaryInsert(block_size);
	_nums = _main_chain;
	_main_chain.clear();
}

void PmergeMe::stashLeftovers(int_vector &leftovers, const size_t &block_size)
{
	if (_nums.size() % (block_size * 2))
	{
		leftovers.insert(leftovers.end(), _nums.end() - block_size, _nums.end());
		_nums.erase(_nums.end() - block_size, _nums.end());
	}
}

void PmergeMe::popLeftovers(int_vector &leftovers)
{
	_nums.insert(_nums.end(), leftovers.begin(), leftovers.end());
}

void PmergeMe::sortSinglePairs(const size_t &block_size)
{
	size_t offset = block_size - 1;
	for (
		iv_iterator it = _nums.begin() + offset, end = _nums.end() - block_size;
		it < end;
		it += block_size * 2
	){
		if (*it > *(it + block_size))
			std::swap_ranges(it - offset, it + 1, it + 1);
		_comparisons++;
	}
}

void PmergeMe::constructMainChain(const size_t &block_size)
{
	size_t offset = block_size - 1;
	for (
		iv_iterator it = _nums.begin() + offset + block_size;
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
}

/*
	Returns the number of elements to insert based on the given step (starting at 1)
	The mathematical sequence is: 0, 2, 2, 6, 10, 22, 42, etc...
*/
size_t PmergeMe::nextInSequence(const size_t &step)
{
	return (round((pow(2, step) + pow(-1, step)) / 3));
}

size_t PmergeMe::getNumsToInsert(const size_t &step, const size_t &block_size)
{
	if (!_nums.size())
		return 0;
	if (step <= 1)
		return step;
	size_t next = nextInSequence(step);
		return ((next <= _nums.size() / block_size) ? next : _nums.size() / block_size);
}

size_t PmergeMe::getInsertionBlockSize(const size_t &step, const size_t &block_size)
{
	size_t	size = (pow(2, step) - 1) * block_size;
	return ((size <= _main_chain.size()) ? size : _main_chain.size());
}

void PmergeMe::binaryInsert(const size_t &block_size, const size_t &step)
{
	if (_nums.size() == 0)
		return ;
	size_t	to_insert = getNumsToInsert(step, block_size);
	size_t	insertion_block = getInsertionBlockSize(step, block_size);

	for (iv_iterator position, value; to_insert > 0; --to_insert)
	{
		value = _nums.begin() + (to_insert * block_size) - 1;
		position = lowerBound(_main_chain.begin(), _main_chain.begin() + insertion_block, *value, block_size);
		_main_chain.insert(position, value - (block_size -1), value + 1);
	}
	to_insert = getNumsToInsert(step, block_size);
	_nums.erase(_nums.begin(), _nums.begin() + (to_insert * block_size));
	binaryInsert(block_size, step + 1);
}

/*
	Custom implementation of std::lower_bound to handle block_size (stride size).
	A similar output could be achieved with creating a custom iterator.
*/
iv_iterator PmergeMe::lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size)
{
	iv_iterator middle;
	size_t range_size, half_step;

	range_size = std::distance(begin, end) / block_size;

	while (range_size > 0)
	{
		middle = begin + block_size - 1;
		half_step = range_size / 2;
		std::advance(middle, half_step * block_size);

		_comparisons++;
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

//  ============| GETTERS |=============

const int_vector &PmergeMe::getNums() const { return _nums; };

const size_t &PmergeMe::getComparisons() const { return _comparisons; };

//  ========| NON MEMBER |=========
std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs)
{
	for (size_t i = 0; i < rhs.getNums().size(); ++i)
		os << ' ' << rhs.getNums()[i];
	os << std::endl;
	return os;
}
