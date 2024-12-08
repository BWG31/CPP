#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <cmath>

# define FIRST_INSERTION_STEP (2)

extern int COMPS;

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;

void PmergeMe(int_vector &nums, size_t block_size);

void stashLeftovers(int_vector &nums, int_vector &leftovers, size_t block_size);
void restoreLeftovers(int_vector &nums, int_vector &leftovers);
void sortSinglePairs(int_vector &nums, size_t block_size);
void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size);
void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size, size_t step);
iv_iterator lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size);
size_t getNumsToInsert(size_t step, const int_vector &nums, size_t block_size);

// TESTERS
void printVector(int_vector &vec, const std::string &str);


#endif
