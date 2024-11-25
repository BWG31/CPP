#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		std::vector<int> &getValues();

	private:
		std::vector<int> values;
};

#endif