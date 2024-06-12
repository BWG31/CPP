#include "Cat.hpp"
#include <new>

// =============== CONSTRUCTORS ==================
Cat::Cat() : Animal("Cat")
{
	std::cout	<< GREEN << "-- Cat constructor called for: "
				<< _type << RESET << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout	<< GREEN << "-- Cat copy constructor called copying: "
				<< other._type << RESET << std::endl;
	_brain = new Brain();
	*this = other;
}

// ================ DESTRUCTOR ===================
Cat::~Cat()
{
	std::cout	<< RED << "-- Cat destructor called for: "
				<< _type << RESET << std::endl;
	delete _brain;
}

// ============= OPERATOR OVERLOAD ===============
Cat &Cat::operator=(const Cat &rhs)
{
	_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

// ================= METHODS ====================
void Cat::makeSound() const
{
	std::cout << "🔈🔈 MEOW MEOW 🔈🔈" << std::endl;
}

void Cat::newIdea(std::string new_idea)
{
	for (int i = 0; i < IDEA_COUNT ; i++)
	{
		if (this->_brain->getIdea(i).length() == 0)
		{
			this->_brain->setIdea(i, new_idea);
			return ;
		}
	}
	std::cout << YELLOW << "Cat's brain is full." << RESET << std::endl;
}

void Cat::printIdeas()
{
	std::string idea;
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		idea = this->_brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Cat idea[" << i << "]: " << idea << std::endl;
	}
}
