#include <array>
#include <iostream>
#include <utility>

// template <class T, T N, class I = std::make_integer_sequence<T, N>>
// struct factorial;

// template <class T, T N, T... Is>
// struct factorial<T,N,std::index_sequence<T, Is...>> {
//    static constexpr T value = (static_cast<T>(1) * ... * (Is + 1));
// };

template<unsigned int n>
struct factorial
{
    enum
    {
        value = n * factorial<n - 1>::value
    };
};

template<>
struct factorial<0>
{
    enum { value = 1 };
};


