#include "Combinatorika.h"

double Combinatorika::LongCombination(int k, int n)
{
    return LongFactorial(n) / (LongFactorial(k) * LongFactorial(n - k));
}

double Combinatorika::LongRazmeshenie(int k, int n)
{
    return LongFactorial(n) / LongFactorial(n - k);
}

double Combinatorika::LongPosledovarelnost(int n)
{
    return LongFactorial(n);
}

/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/
long int Combinatorika::Combination(int k, int n)
{
    return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/
long int Combinatorika::Razmeshenie(int k, int n)
{
    return Factorial(n) / Factorial(n - k);
}

/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/
long int Combinatorika::Posledovarelnost(int n)
{
    return Factorial(n);
}