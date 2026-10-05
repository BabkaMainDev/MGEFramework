#include "MatematikaCore.h"
#include <iostream>
#include <math.h>
#include "Macros.h"
#include "UserValues/BigValues.h"

#define PI 3.14159265359

double MatematikaCore::SumKorney(double x1, double x2)
{
    double sum = x1 + x2;
    std::cout << "Summa:" << sum << std::endl;
    return sum;
}

double MatematikaCore::VozvestiVstepen(double n, int stepen)
{
    long double result = 1;
    if (stepen > 0)
    {
        for (int i = 1; i <= stepen; i++)
        {
            result *= n;
        }
    }
    else 
	{
		stepen = -stepen;

		for (int i = 1; i <= stepen; i++)
        {
            result *=  1.f / n;
        }
	}
    return result;
}

void MatematikaCore::Diskriminant(int a, int b, int c)
{
    double diskriminant = VozvestiVstepen(b, 2) - 4 * a * c;
    double x1 = 0, x2 = 0;
    std::cout << "Diskriminant:" << diskriminant << std::endl;
    if (diskriminant > 0) diskriminant = sqrt(diskriminant);
    std::cout << "Koren iz Diskriminant:" << diskriminant << std::endl;
    if (diskriminant > 0)
    {
        x1 = (-b + diskriminant) / (2 * a);
        x2 = (-b - diskriminant) / (2 * a);
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

/*Big rasscheti*/
long double MatematikaCore::LongFactorial(int n)
{
    long double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

/*small rascheti do 20!*/
long int MatematikaCore::Factorial(int n)
{
    long int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double MatematikaCore::CalculateRad(double deg)
{
    return deg * (PI / 180);
}

double MatematikaCore::CalculateDegFromRad(double rad)
{
    return rad * (180 / PI);
}

double MatematikaCore::sin(double x)
{
    double result = 0;
    int stepen = 1;
    int i = 1;
    x = fmod(x, 2*PI);
    for (int k = 1; k < 10; k++)
    {
        result += i * VozvestiVstepen(x, stepen) / Factorial(stepen);
        stepen += 2;
        i *= -1;
    }

    return result;
}

void MatematikaCore::PoligonDlyaTestov()
{
    Diskriminant(1, -6, 3);
    std::cout << "Factarial:" << Factorial(5)			<< std::endl;
    std::cout << VozvestiVstepen(67, 42)				<< std::endl;
    std::cout << "rad = " << CalculateRad(52)			<< std::endl;
    std::cout << "deg = " << CalculateDegFromRad(1)		<< std::endl;
    std::cout << Euler									<< std::endl;
    std::cout << "samopis sin =" << sin(90)				<< std::endl;
	std::cout << Min(-4, -11)							<< std::endl;
	std::cout << Max(65, 765)							<< std::endl;
	std::cout << Clamp(45, 42, 52)						<< std::endl;
	std::cout << Abs(-52)								<< std::endl;
	std::cout << ClampedLerp(0, 198, 0.5)				<< std::endl;
	std::cout << Lerp(0, 198, 67)						<< std::endl;
	std::cout << Dist(4, 11, 0, 3)						<< std::endl;
}

double MatematikaCore::Min(double A, double B) { return A < B ? A : B; }
double MatematikaCore::Max(double A, double B) { return A > B ? A : B; }

double MatematikaCore::Abs(double Value){ return Value < 0 ? -Value : Value; }

inline double MatematikaCore::ClampedLerp(double Min, double Max, double Val){ return Clamp((Min + (Max - Min)* Val), Min, Max); }
inline double MatematikaCore::Lerp(double Min, double Max, double Val){ return Min + (Max - Min)* Val; }

inline double MatematikaCore::Sign(double Val) { if(Val < 0) return -1; if(Val > 0) return 1; return 0;}
inline double MatematikaCore::Dist(double x1, double x2, double y1, double y2) { return Sqrt(VozvestiVstepen(x2 - x1, 2) + VozvestiVstepen(y2 - y1, 2)); }

double MatematikaCore::Clamp(double Value, double Min, double Max)
{
	if (Value > Max) return Max;
    if (Value < Min) return Min;
	return Value;
}
