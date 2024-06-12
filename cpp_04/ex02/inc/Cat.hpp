#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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