#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE (4)

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_items[INVENTORY_SIZE];
		int			_free_slots;

		void destroy_all_items();
	public:
		// Constructors | Destructor
		Character(std::string new_name = "Unknown");
		Character(const Character &other);
		~Character();

		// Operator Overloads
		Character &operator=(const Character &rhs);

		// Methods
		std::string const & getName() const;
		void  equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria *getItem(int idx);

};

#endif