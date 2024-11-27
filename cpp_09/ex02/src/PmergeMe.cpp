#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS |==========
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::PmergeMe(const int_vector &input) :
	values(input),
	leftover(false),
	leftover_value(-1) {}

//  ===========| DESTRUCTOR |===========
PmergeMe::~PmergeMe() {}

//  =======| OPERATOR OVERLOADS |=======
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		values = rhs.values;
		this->leftover = rhs.leftover;
		this->leftover_value = rhs.leftover_value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs)
{
	os << "values:";
    for (std::size_t i = 0, size = rhs.getValues().size(); i < size; ++i)
    {
        os << ' ' << rhs.getValues()[i];
    }
	os << std::endl;
    if (rhs.getLeftover())
	{
    	os << "leftover: " << rhs.getLeftoverValue() << std::endl;
	}
	return os;
}

//  ============| METHODS |=============

void PmergeMe::sort()
{
	sortPairs();

	/*
		split values into sorted pairs b1|a1
			leftover stored seperately b(n/2 + 1)
		Create main chain b1 > a1..a(n/2)
		Arrange sequence for remaining b elements
		Binary insert remaining elements to main chain
	*/
}

void PmergeMe::sortPairs()
{
	for (
		int_vector::iterator it = values.begin(),
		end = (values.size() % 2) ? values.end() - 1 : values.end();
		it != end;
		it += 2
	)
	{
		if (*it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
}

//  ========| GETTERS |=========

const int_vector &PmergeMe::getValues() const {return values; };

const bool &PmergeMe::getLeftover() const { return leftover; };

const int &PmergeMe::getLeftoverValue() const { return leftover_value; };

//  ========| VIRTUAL METHODS |=========
