#include "Floor.hpp"
#include <iostream>
#include <cstring>

//	============= CONSTRUCTORS =============
Floor::Floor() : _discarded() , _floor_count(0) {}

Floor::Floor(const Floor &other)
{
	*this = other;
}

//	============== DESTRUCTOR ==============
Floor::~Floor()
{
	int i;
	for (i = 0; i < _floor_count; i++)
	{
		std::cout	<< RED << "Deleting Floor[" << i << "]: "
					<< _discarded[i]->getType() << std::endl;
		delete _discarded[i];
		_discarded[i] = nullptr;
	}
	if (i)
	{
		std::cout	<< RED << "Floor Destructor deleted "
					<< i << " objects" << RESET << std::endl;
	}
}

//	========== OPERATOR OVERLOADS ==========
Floor &Floor::operator=(const Floor &rhs)
{
	this->_floor_count = rhs._floor_count;
	memcpy(this->_discarded, rhs._discarded, sizeof(_discarded));
	return (*this);
}

//	=============== METHODS ===============
void Floor::append(AMateria *materia)
{
	if (!materia) return ;
	if (_floor_count >= MAX_OBJECTS)
	{
		std::cerr	<< YELLOW << "Floor object limit reached: deleting object"
					<<	RESET << std::endl;
		delete materia;
	}
	else
		_discarded[_floor_count++] = materia;
}

void Floor::pop(AMateria *materia)
{
	if (!materia) return ;
	for (int i = 0; i < _floor_count; i++)
		if (_discarded[i] == materia)
			_discarded[i] = _discarded[--_floor_count]; // Last takes place of popped
}

bool Floor::onFloor(AMateria *materia)
{
	for (int i = 0; i < _floor_count; i++)
		if (_discarded[i] == materia) return true;
	return false;
}

AMateria* Floor::pickUp(int idx)
{
	if (idx < 0 || idx >= MAX_OBJECTS || !_discarded[idx])
		return nullptr;
	AMateria* to_pick_up = _discarded[idx];
	pop(to_pick_up);
	return (to_pick_up);
}
