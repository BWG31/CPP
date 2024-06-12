#include "Dog.hpp"
#include <new>

// =============== CONSTRUCTORS ==================
Dog::Dog() : Animal("Dog")
{
	std::cout	<< GREEN << "-- Dog constructor called for: "
				<< _type << RESET << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	std::cout	<< GREEN << "-- Dog copy constructor called copying: "
				<< other._type << RESET << std::endl;
	_brain = new Brain();
	*this = other;
}

// ================ DESTRUCTOR ===================
Dog::~Dog()
{
	std::cout	<< RED << "-- Dog destructor called for: "
				<< _type << RESET << std::endl;
	delete _brain;
}

// ============= OPERATOR OVERLOAD ===============
Dog &Dog::operator=(const Dog &rhs)
{
	_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

// ================= METHODS ====================
void Dog::makeSound() const
{
	std::cout << "🔈🔈 WOOF WOOF 🔈🔈" << std::endl;
}

void Dog::newIdea(std::string new_idea)
{
	for (int i = 0; i < IDEA_COUNT ; i++)
	{
		if (this->_brain->getIdea(i).length() == 0)
		{
			this->_brain->setIdea(i, new_idea);
			return ;
		}
	}
	std::cout << YELLOW << "Dog's brain is full." << RESET << std::endl;
}

void Dog::printIdeas()
{
	std::string idea;
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		idea = this->_brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Dog idea[" << i << "]: " << idea << std::endl;
	}
}
