#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const &other) : std::stack<T>(other) {};
		~MutantStack() {};
	
		MutantStack &operator=(MutantStack const &rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); };
		const_iterator end() const { return this->c.end(); };

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); };
		reverse_iterator rend() { return this->c.rend(); };
};

#endif