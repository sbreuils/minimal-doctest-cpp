#include <doctest/doctest.h>

#include <factorial.hpp>


TEST_CASE("template meta factorial")
{
    SUBCASE("n=0 and n=1"){
        CHECK_EQ(factorial<0>::value, 1);
        CHECK_EQ(factorial<1>::value, factorial<0>::value);
    }

    SUBCASE("n > 1 "){
        const unsigned int n=12;
        CHECK_EQ(factorial<n>::value,n*factorial<n-1>::value);
        CHECK_EQ(factorial<n>::value,479001600);
    }
}