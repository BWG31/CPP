#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

//  ==========| CONSTRUCTORS |==========
template <class T>
Array<T>::Array() : _size(0), elements(NULL) {}

Array::Array(const Array &other)
{
    //  DEFAULT
}

//  ===========| DESTRUCTOR |===========
Array::~Array()
{
    //  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======
Array &Array::operator=(const Array &rhs)
{
    //  DEFAULT
}

//  ============| METHODS |=============

//  ========| VIRTUAL METHODS |=========

#endif