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
