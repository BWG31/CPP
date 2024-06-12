#include "Brain.hpp"

// =============== CONSTRUCTORS ==================
Brain::Brain()
{
	std::cout	<< GREEN << "-- Brain constructor called -- " << RESET << std::endl;
	
}

Brain::Brain(const Brain &other)
{
	std::cout	<< GREEN << "-- Brain copy constructor called -- " << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
Brain::~Brain()
{
	std::cout	<< RED << "-- Brain destructor called --" << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
Brain &Brain::operator=(const Brain &rhs)
{
	std::memcpy(this->_ideas, rhs._ideas, sizeof(rhs._ideas));
	return (*this);
}

// ================= METHODS ====================
const std::string &Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEA_COUNT)
		std::cout << "Invalid index used for Brain::getIdea(): " << index << std::endl;
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= IDEA_COUNT)
		std::cout << "Invalid index used for Brain::setIdea(): " << index << std::endl;
	this->_ideas[index] = idea;
}
