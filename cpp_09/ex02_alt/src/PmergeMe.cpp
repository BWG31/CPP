#include "PmergeMe.hpp"

void PmergeMe(int_vector &vec)
{
	/*
		sortSinglePairs(vec.begin(), vec.end());
		paired_values = makePairs(vec, leftover);
		subvector = largestElementsVector(vec);
		PmergeMe(subvector);
		rearrangePairedValues(paired_values, subvector);
		vec.empty();
		constructMainChain(vec, paired_values);
		binaryInsert(vec, paired_values, leftover);
	*/
}

void sortSinglePairs(iv_iterator it, iv_iterator end)
{
	for (end = (values.size() % 2) ? end - 1 : end;
		it != end;
		it += 2)
	{
		if (*it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
};

void sortSinglePairs(pv_iterator it, pv_iterator end)
{
	for (end = (values.size() % 2) ? end - 1 : end;
		it != end;
		it += 2)
	{
		if (it.base()->second > (it + 1).base()->second)
			std::swap(*it, *(it + 1));
	}
};

void makePairs(int_vector vec)
{
	for (std::size_t i = 1; i < vec.size(); ++i)
    {
        paired_values.push_back(std::make_pair(vec[i - 1], vec[i]));
        if (++i == vec.size() - 1)
        {
            leftover_value = vec[i];
            leftover = true;
            break;
        }
    }
}

void baseCase(pv_iterator it, size_t size)
{
	if (size == 2)
	{
		if (it.base()->second > (it + 1).base()->second)
			std::swap(*it, *(it + 1));
	}
	return ;
}
