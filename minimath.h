#pragma once

class MiniMath
{
  protected:
    bool mThrowAsserts;

  public:
    MiniMath(bool throwAsserts = false)
        : mThrowAsserts(throwAsserts){};
    int factorial(int n);
    double div(double x, double y);
    int gcd(int a, int b);
    static bool mutPrime(int a, int b);
};