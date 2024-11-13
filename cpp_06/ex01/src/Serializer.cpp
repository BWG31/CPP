#include "Serializer.hpp"

//  ==========| CONSTRUCTORS |==========
Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
Serializer::~Serializer() {}

//  =======| OPERATOR OVERLOADS |=======
Serializer &Serializer::operator=(const Serializer &rhs)
{
    (void)rhs;
    return (*this);
}

//  ============| METHODS |=============

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
