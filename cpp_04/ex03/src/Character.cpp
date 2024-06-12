#include "Character.hpp"

extern Floor *global_floor;

//	============= CONSTRUCTORS =============
Character::Character(std::string new_name) : 
	_name(new_name), _items(), _free_slots(INVENTORY_SIZE) {}

Character::Character(const Character &other)
{
	*this = other;
}

//	============== DESTRUCTOR ==============
Character::~Character()
{
	destroy_all_items();
}

//	========== OPERATOR OVERLOADS ==========
Character &Character::operator=(const Character &rhs)
{
	this->_name = rhs._name;
	this->destroy_all_items();
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (rhs._items[i])
			this->_items[i] = rhs._items[i]->clone();
	return (*this);
}

//	=============== METHODS ===============
std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (!_free_slots)
	{
		global_floor->append(m);
		return ;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!_items[i])
		{
			_items[i] = m;
			if (global_floor->onFloor(m))
				global_floor->pop(m);
			_free_slots--;
			return ;
		}
	}
	std::cerr << _name << "'s item count corrupted" << std::endl;
	global_floor->append(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return ;
	global_floor->append(_items[idx]);
	_items[idx] = nullptr;
	_free_slots++;
}

void Character::use(int idx, ICharacter& target)
{
	AMateria *materia = this->getItem(idx);
	if (materia)
		materia->use(target);
}

AMateria *Character::getItem(int idx)
{
	return (idx >= 0 && idx < INVENTORY_SIZE) ? this->_items[idx] : nullptr;
}

//	========== PRIVATE METHODS ==========
void Character::destroy_all_items()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (_items[i]) delete _items[i];
}
