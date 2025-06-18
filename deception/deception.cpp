#include "deception.h"
#include <cmath>

int Deception::DeceptionProblem(const vector<int>& sol, const int& bit)
{
	int b2d = 0;
	int fx = 0; /*f(x) = |b2d(x) - pow(2, bit - 2)|*/
	for (int i = 1; i <= bit; ++i)
	{
		b2d += sol[i - 1] * pow(2, bit - i);
	};

	fx = abs(b2d - pow(2, bit - 2));

	return fx;
};