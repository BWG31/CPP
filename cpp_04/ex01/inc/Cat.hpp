#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();

		Cat &operator=(const Cat &rhs);

		void makeSound(void) const;
		void newIdea(std::string new_idea);
		void printIdeas();
};

#endif