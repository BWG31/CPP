#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS |==========
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::PmergeMe(const std::vector<int> &input) :
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
		this->pairs = rhs.pairs;
		this->leftover = rhs.leftover;
		this->leftover_value = rhs.leftover_value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs)
{
    for (std::size_t i = 0, size = rhs.getPairs().size(); i < size; ++i)
    {
        os << rhs.getPairs()[i].first << " | " << rhs.getPairs()[i].second << std::endl;
    }
    if (rhs.getLeftover())
	{
    	os << "leftover: " << rhs.getLeftoverValue() << std::endl;
	}
	return os;
}

//  ============| METHODS |=============

void PmergeMe::sort()
{
	splitIntoPairs();

	/*
		split values into sorted pairs b1|a1
			leftover stored seperately b(n/2 + 1)
		Create main chain b1 > a1..a(n/2)
		Arrange sequence for remaining b elements
		Binary insert remaining elements to main chain
	*/
}

void PmergeMe::splitIntoPairs()
{
	for (std::size_t i = 1; i < values.size(); ++i)
    {
        pairs.push_back(std::make_pair(values[i - 1], values[i]));
        if (++i == values.size() - 1)
        {
            leftover_value = values[i];
            leftover = true;
            break;
        }
    }
}

//  ========| GETTERS |=========

const v_pairs &PmergeMe::getPairs() const { return pairs; };

const bool &PmergeMe::getLeftover() const { return leftover; };

const int &PmergeMe::getLeftoverValue() const { return leftover_value; };

//  ========| VIRTUAL METHODS |=========
