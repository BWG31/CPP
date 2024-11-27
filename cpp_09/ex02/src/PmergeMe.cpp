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

//  ============| PUBLIC METHODS |=============

void PmergeMe::sort()
{
	sortSinglePairs(values.begin(), values.end());
	makePairs();

	/*
		split values into sorted pairs b1|a1
			leftover stored seperately b(n/2 + 1)
		Create main chain b1 > a1..a(n/2)
		Arrange sequence for remaining b elements
		Binary insert remaining elements to main chain
	*/
}

//  ============| PRIVATE METHODS |=============

void PmergeMe::sortSinglePairs(iv_iterator it, iv_iterator end)
{
	for (end = (values.size() % 2) ? end - 1 : end;
		it != end;
		it += 2)
	{
		if (*it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
};

void PmergeMe::sortSinglePairs(pv_iterator it, pv_iterator end)
{
	for (end = (values.size() % 2) ? end - 1 : end;
		it != end;
		it += 2)
	{
		if (it.base()->second > (it + 1).base()->second)
			std::swap(*it, *(it + 1));
	}
};

void PmergeMe::makePairs()
{
	for (std::size_t i = 1; i < values.size(); ++i)
    {
        paired_values.push_back(std::make_pair(values[i - 1], values[i]));
        if (++i == values.size() - 1)
        {
            leftover_value = values[i];
            leftover = true;
            break;
        }
    }
}

void PmergeMe::mergeInsertPairs(pv_iterator it, pv_iterator end)
{
	size_t size = end - it;

	if (size < 3)
		return baseCase(it, size);
	
	// paired_values.insert()
}

void PmergeMe::baseCase(pv_iterator it, size_t size)
{
	if (size == 2)
	{
		if (it.base()->second > (it + 1).base()->second)
			std::swap(*it, *(it + 1));
	}
	return ;
}

//  ========| GETTERS |=========

const int_vector &PmergeMe::getValues() const {return values; };

const bool &PmergeMe::getLeftover() const { return leftover; };

const int &PmergeMe::getLeftoverValue() const { return leftover_value; };

//  ========| VIRTUAL METHODS |=========
