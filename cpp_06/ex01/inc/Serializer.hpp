#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer
{
	public:
		Serializer &operator=(const Serializer &rhs);
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif