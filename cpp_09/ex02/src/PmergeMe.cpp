#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS |==========
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
PmergeMe::~PmergeMe() {}

//  =======| OPERATOR OVERLOADS |=======
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    this->values = rhs.values;
    return *this;
}

//  ============| METHODS |=============

std::vector<int> &PmergeMe::getValues()
{
    return this->values;
}

//  ========| VIRTUAL METHODS |=========
