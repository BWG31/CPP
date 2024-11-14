#ifndef INCREMENT_HPP
# define INCREMENT_HPP

#include <string>

template <class T> void increment(T &value)
{
	value += 1;
}

template <> void increment(std::string &value)
{
	value += "1";
}

#endif