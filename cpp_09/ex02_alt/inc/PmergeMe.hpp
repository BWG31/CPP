#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>

typedef std::vector<int> int_vector;
typedef int_vector::iterator iv_iterator;
typedef std::vector<std::pair<int, int> > pair_vector;
typedef pair_vector::iterator pv_iterator;

void PmergeMe(int_vector vec);

pair_vector makePairs(int_vector &vec);
void mergeInsertPairs(pv_iterator it, pv_iterator end);
void baseCase(pv_iterator it, size_t size);

void sortSinglePairs(pv_iterator it, pv_iterator end);
void sortSinglePairs(iv_iterator it, iv_iterator end);

#endif