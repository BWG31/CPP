#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
		void newIdea(std::string new_idea);
		void printIdeas();
};

#endif