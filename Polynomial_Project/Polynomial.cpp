#include <iostream>
#include "Polynomial.h"

using namespace std;

void Polynomial::enterPolynomial()
{
	for (int i = power;i >= 0;i--)
	{
		cin >> values[i];
	}
}

void Polynomial::showPolynomial()
{
	for (int i = power;i >= 0;i--)
	{
		if (values[i] != 0 && values[i] != 1)
		{
			if( values[i] == -1&& i != 0)cout <<"-";
			else cout << values[i];
		}
		else if (i == 0 && (values[i] == 1 || values[i] == -1))cout << values[i];
		if (i > 1 && values[i] != 0)cout << "x^" << i;
		else if ((i == 1|| i == -1)&& values[i] != 0)cout << "x";
		if (values[i - 1] > 0) cout << "+";
	}
}
