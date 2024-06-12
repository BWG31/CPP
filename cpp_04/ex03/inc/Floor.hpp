#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

# define MAX_OBJECTS (100)

class AMateria;

class Floor
{
	private:
		AMateria *_discarded[MAX_OBJECTS];
		int	_floor_count;
	public:
		// Constructors | Destructor
		Floor();
		Floor(const Floor &other);
		~Floor();

		// Operator Overloads
		Floor &operator=(const Floor &rhs);

		// Methods
		void append(AMateria *materia);
		void pop(AMateria *materia);
		bool onFloor(AMateria *materia);
		AMateria* pickUp(int idx);
};

#endif