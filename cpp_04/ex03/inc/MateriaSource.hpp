#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MS_MEMORY_SIZE (4)

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_memory[MS_MEMORY_SIZE];
		int			_free_slots;	
	public:
		// Constructors | Destructor
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		// Operator Overloads
		MateriaSource &operator=(const MateriaSource &rhs);

		// Methods
		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const & type);
	
		// Getters
		int getFreeSlot();
};

#endif