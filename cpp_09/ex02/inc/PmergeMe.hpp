#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>

typedef std::vector<int> int_vector;

class PmergeMe
{
	public:
		// Constructors | Destructor
		PmergeMe(const std::vector<int> &input);
		~PmergeMe();

		void sort();

		// getters
		const int_vector &getValues() const;
		const bool &getLeftover() const;
		const int &getLeftoverValue() const;

	private:
		int_vector	values;
		bool		leftover;
		int			leftover_value;

		void sortPairs();

		// Unused coplien elements
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs);

#endif