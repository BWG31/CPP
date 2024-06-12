#include "MateriaSource.hpp"

extern Floor *global_floor;

//	============= CONSTRUCTORS =============
MateriaSource::MateriaSource() : _memory(), _free_slots(MS_MEMORY_SIZE) {}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

//	============== DESTRUCTOR ==============
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MS_MEMORY_SIZE; i++)
		if (_memory[i])
			delete _memory[i];
}

//	========== OPERATOR OVERLOADS ==========
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	int i;
	for (i = 0; i < MS_MEMORY_SIZE; i++)
	{
		if (_memory[i])
			delete _memory[i];
		if (rhs._memory[i])
			_memory[i] = rhs._memory[i]->clone();
	}		
	_free_slots = rhs._free_slots;
	return (*this);
}

//	=============== METHODS ===============
void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	int idx = getFreeSlot();
	switch (idx){
		case -2:
			std::cerr << "MateriaSource _free_slots corrupted\n";
		case -1:
			global_floor->append(materia);
			break;
		default:
			_memory[idx] = materia;
			_free_slots--;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MS_MEMORY_SIZE; i++)
	{
		if (_memory[i] && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	return (nullptr);
}

//	=============== GETTERS ===============
int MateriaSource::getFreeSlot()
{
	if (!_free_slots)
		return (-1);
	for (int i = 0; i < MS_MEMORY_SIZE; i++)
		if (!_memory[i]) return (i);
	return (-2); // IF WE GET HERE THERE IS AN ISSUE WITH _free_slots count
}
