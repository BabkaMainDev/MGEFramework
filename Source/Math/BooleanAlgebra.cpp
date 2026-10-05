

#include <iostream>
#include <cmath>
#include "BooleanAlgebra.h"
#include "Combinatorika.h"
#include "UserValues/BigValues.h"

Vikluchatel::Vikluchatel()
{
    A = false;
    B = false;
    C = false;
}

bool Vikluchatel::F(bool _A, bool _B, bool _C)
{
    A = _A; //anal
    B = _B;
    C = _C;

    bool resultXOR = A ^ B ^ C; // XOR gotovoe
    //int count = A * !B * !C + !A * B * !C + !A * !B * C + A * B * C; tak sebe variant
    bool result = (A && !B && !C) || (!A && B && !C) || (!A && !B && C) || (A && B && C); // XOR samopal
    //if (A == 0 || B == 0 || C == 0) result = false;

    std::cout << resultXOR << std::endl;

    return resultXOR;
}

/*double SumKorney(double x1, double x2)
{
    double sum = x1 + x2;
    std::cout << "Summa:" << sum << std::endl;
    return sum;
}

double VozvestiVstepen(double n, int stepen)
{
    long double result = 1;
    if (stepen > 0) 
    {
        for (int i = 1; i <= stepen; i++)
        {
            result *= n;
        }
    }
    else { result = 1; }
    return result;
}

void Diskriminant(int a, int b, int c)
{
    double diskriminant = VozvestiVstepen(b, 2) - 4 * a * c;
    double x1 = 0, x2 = 0;
    std::cout << "Diskriminant:" << diskriminant << std::endl;
    if (diskriminant > 0) diskriminant = sqrt(diskriminant);
    std::cout << "Koren iz Diskriminant:" << diskriminant << std::endl;
    if (diskriminant > 0)
    {
        x1 = ( - b + diskriminant) / (2 * a);
        x2 = ( - b - diskriminant) / (2 * a);
        SumKorney(x1, x2);
    }
    else if (diskriminant == 0)
    {
        x1 = -b / (2 * a);
    }
    else
    {
        std::cout << "diskriminant < 0" << std::endl;
    }
    std::cout << x1 << std::endl << x2 << std::endl;
}

int Factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}*/