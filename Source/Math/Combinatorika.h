#pragma once

#include "MatematikaCore.h"

class Combinatorika : public MatematikaCore
{
public:
	/*dlinnie rasscheti do 1743!*/
	double LongCombination(int k, int n);
	double LongRazmeshenie(int k, int n);
	double LongPosledovarelnost(int n);
	
	/*korotkie rasscheti do 20!*/

	/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/
	long int Combination(int k, int n);
	/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/
	long int Razmeshenie(int k, int n);
	/*!!!!!!!!!!! DO 20! !!!!!!!!!!*/	
	long int Posledovarelnost(int n);
};