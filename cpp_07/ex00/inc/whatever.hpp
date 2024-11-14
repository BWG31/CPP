#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T> T min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <class T> T max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif