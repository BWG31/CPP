#include "PmergeMe.hpp"

//  ==========| VECTOR |==========

void PmergeMe(const std::vector<int> &input)
{
    std::vector<int> values(input);

    // split values into sorted pairs b1|a1
        // leftover stored seperately b(n/2 + 1)
    // Create main chain b1 > a1..a(n/2)
    // Arrange sequence for remaining b elements
    // Binary insert remaining elements to main chain
}
