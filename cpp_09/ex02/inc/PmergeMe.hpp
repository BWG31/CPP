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
	
		const int_vector	&getNums() const;
		const size_t		&getComparisons() const;

	private:
		int_vector	_nums;
		size_t		_comparisons;

		const static size_t	_firstInsertionStep = 2;
	// Unused coplien elements
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs);

#endif