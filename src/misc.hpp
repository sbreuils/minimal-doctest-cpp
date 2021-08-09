
#ifndef MISCE
#define MISCE


#include <array>
#include <iostream>




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


#endif
