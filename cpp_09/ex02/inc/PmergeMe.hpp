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

class PmergeMe
{
	public:
		// Constructors | Destructor
		PmergeMe(const int_vector &input);
		~PmergeMe();

		void sort();

		// getters
		const int_vector &getValues() const;
		const bool &getLeftover() const;
		const int &getLeftoverValue() const;

	private:
		int_vector	values;
		pair_vector paired_values;
		bool		leftover;
		int			leftover_value;

		void makePairs();
		void mergeInsertPairs(pv_iterator it, pv_iterator end);
		void baseCase(pv_iterator it, size_t size);

		// Templated methods
		void sortSinglePairs(pv_iterator it, pv_iterator end);
		void sortSinglePairs(iv_iterator it, iv_iterator end);

		// Unused coplien elements
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs);

#endif