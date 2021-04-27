#include <doctest/doctest.h>

#include <misc.hpp>
#include <sys/_types/_key_t.h>


TEST_CASE("factorial with static array")
{
    SUBCASE("binom with k=0 and n=0"){
        CHECK_EQ(ubinomial(0,0), 1);
        CHECK_EQ(ubinomial(4,0), 1);
    }

    SUBCASE("binom with k=1 and any n "){
        int n = 10; // /todo random
        CHECK_EQ(ubinomial(n,1), n);
        CHECK_EQ(ubinomial(n,1), ubinomial(n,n-1));
    }

    SUBCASE("binom with any k and n "){
        int n = 15; // /todo random
        int k = 4; 
        CHECK_EQ(ubinomial(n,k), 1365);// number of quadvectors in qcga
    }
}