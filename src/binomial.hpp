#ifndef BINOMIAL // include guard
#define BINOMIAL


#include <vector>
#include <algorithm>


// Returns value of Binomial Coefficient C(n, k)
int ubinom(const int n, const int k)
{
    std::vector<std::vector<int>> C(n + 1, std::vector<int>(k + 1,0));
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= std::min(i, k); j++) {

            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}


#endif