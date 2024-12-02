#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>
# include <algorithm>

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;

void PmergeMe(int_vector &nums, size_t block_size);

void baseCase(int_vector &nums, size_t block_size);
void sortSinglePairs(int_vector &nums, size_t block_size);
void constructMainChain(int_vector &main_chain, int_vector &nums, size_t block_size);
void binaryInsert(int_vector &main_chain, int_vector &nums, size_t block_size);
iv_iterator lowerBound(iv_iterator begin, iv_iterator end, const int &value, const size_t &block_size);

// TESTERS
void printVector(int_vector &vec);

#endif