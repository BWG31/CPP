#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

//  ==========| CONSTRUCTORS |==========
template <class T>
Array<T>::Array() : _size(0), _elements(NULL) {}

template <class T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _elements = new T[n];
    for (size_t i = 0; i < _size; ++i)
        _elements[i] = 0;
}

template <class T>
Array<T>::Array(const Array<T> &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
template <class T>
Array<T>::~Array()
{
    delete [] _elements;
}

//  =======| OPERATOR OVERLOADS |=======
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this == &rhs)
        return (*this);
    _size = rhs.size();
    if (_size)
    {
        _elements = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _elements[i] = rhs._elements[i];
    }
    else
        _elements = NULL;
    return (*this);
}

template <class T>
T &Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Out of range access on Array");
    return (_elements[index]);
}

template <class T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Out of range access on Array");
    return (_elements[index]);
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Array<T> &rhs)
{
    os << "=== ARRAY | addr: " << &rhs << " size: " << rhs.size() << " ===\n";
	for (size_t i = 0; i < rhs.size(); ++i)
		os << "[" << i << "]: " << rhs[i] << '\n';
	os << "=== END ===" << std::endl;
    return (os);
}

//  ============| METHODS |=============

template <class T>
size_t Array<T>::size() const
{
    return (this->_size);
}

#endif