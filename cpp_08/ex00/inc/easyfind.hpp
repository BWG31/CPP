#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator iter;

    for (iter = container.begin(); iter != container.end(); ++iter)
        if (*iter == num)
            break;
    return iter;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int num)
{
    typename T::const_iterator iter;

    for (iter = container.begin(); iter != container.end(); ++iter)
        if (*iter == num)
            break;
    return iter;
}

#endif