#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <cmath>

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;

void PmergeMe(int_vector &nums, size_t block_size);

void baseCase(int_vector &nums, size_t block_size);
void stashLeftovers(int_vector &nums, int_vector &leftovers, size_t block_size);
void restoreLeftovers(int_vector &nums, int_vector &leftovers);
void sortSinglePairs(int_vector &nums, size_t block_size);
void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size);
void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size);
iv_iterator lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size);
size_t getNumsToInsert(size_t step, const int_vector &nums, size_t block_size);

// TESTERS
void printVector(int_vector &vec, const std::string &str);

void binaryInsertRec(int_vector &main_chain, int_vector &nums, size_t block_size, size_t step);

#endif

/*



	block_size =	2
	offset =		1
	inserted =		0	= (4 - 4) / 2
	to_insert =		1
	n	=			0	= (1 - 1) * 2

	FOR (t_insert != 0; --to_insert)

	*position	=	
	*value		=	4
	paired_value=	7





	block_size = 2
	toinsert = 1
	idx = (to_insert * block_size) - 1 = 1 

*/