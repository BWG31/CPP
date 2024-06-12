#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

# define IDEA_COUNT (100)

class Brain
{
	private:
		std::string _ideas[IDEA_COUNT];
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &rhs);

		// Methods
		const std::string &getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif