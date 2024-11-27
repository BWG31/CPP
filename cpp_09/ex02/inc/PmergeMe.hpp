#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <utility>
# include <iostream>
# include <iomanip>

typedef std::vector<std::pair<int, int> > v_pairs;

class PmergeMe
{
	public:
		// Constructors | Destructor
		PmergeMe(const std::vector<int> &input);
		~PmergeMe();

		void sort();

		// getters
		const v_pairs &getPairs() const;
		const bool &getLeftover() const;
		const int &getLeftoverValue() const;

	private:
		std::vector<int> values;
		v_pairs	pairs;
		bool	leftover;
		int		leftover_value;
		
		void splitIntoPairs();

		// Unused coplien elements
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &rhs);

#endif