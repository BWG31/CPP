#include "PmergeMe.hpp"
#include <iostream>
//  ==========| VECTOR |==========

void PmergeMe(const std::vector<int> &input)
{
    typedef std::vector<int>::iterator val_iterator;
    std::vector<int> values(input);

    // split values into sorted pairs b1|a1
    std::vector<std::pair<int, int> > pairs;
    int *last;
    // for (std::size_t i = 1; i < values.size(); i += 2)
    // {
    //     pairs.push_back(std::make_pair(values[i - 1], values[i]));
    // }
    val_iterator it = values.begin();
    for (int i = 0; it + 1 != values.end(); ++i)
    {
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    if (it != values.end())
        last = new int(*it);
    
    for (std::size_t i = 0; i < pairs.size(); ++i)
        std::cout << pairs[i].first << " | " << pairs[i].second << std::endl;
    if (last)
    {
        std::cout << "last: " << *last << std::endl;
        delete last;
    }
        // leftover stored seperately b(n/2 + 1)
    // Create main chain b1 > a1..a(n/2)
    // Arrange sequence for remaining b elements
    // Binary insert remaining elements to main chain
}
