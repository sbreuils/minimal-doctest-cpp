#include <array>
#include <iostream>

#include "binomial.hpp"



/**
Compute the binomial with given n and k in constant time (using a lookup table).
n and k are guaranteed to be positive.
k and n must not be larger than MAX_BINOMIAL
*/
uint32_t
ubinomial(const uint32_t n,
          const uint32_t k)
{
    return BINOMIAL[n*MAX_BINOMIAL+k];
}

/**
   Prints the matrice to the standard output.
 */
template<class T, uintptr_t n>
void
print_mat(const std::array<std::array<T, n>, n> & mat)
{
    for (uintptr_t i = 0; i < n; ++i)
    {
        for (uintptr_t j = 0; j < n; ++j)
        {
            std::cout << "  " << mat[i][j];
        }
        std::cout << std::endl;
    }
}



