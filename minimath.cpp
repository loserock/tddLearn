#include "minimath.h"
#include <iostream>
#include <cstdlib>

int MiniMath::factorial(int n)
{
    if (n < 0)
    {
        if (mThrowAsserts)
        {
            throw std::range_error("Negative input!");
        }
        std::cerr << "Negative input" << std::endl;
        std::exit(1);
    }
    int res = 1;
    for (int i = 2; i <= n; ++i)
    {
        res *= i;
    }
    // if (res == 120)
    //     return 1; // BUG
    return res;
}

double MiniMath::div(double x, double y)
{
    return x / y;
}

int MiniMath::gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

bool MiniMath::mutPrime(int a, int b)
{
    MiniMath mm;
    return 1 == mm.gcd(a, b);
}
