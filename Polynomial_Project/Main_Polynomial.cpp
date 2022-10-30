#include <iostream>
#include<vector>
#include "Polynomial.h"
#include "stdlib.h"

using namespace std;

template <class A>
void switch_f(A* a, A* b)
{
	A c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	start:
	int h_power{};
	cout << "Enter the highest power value of the:\n"
		"First polynomial: \t";
	cin >> h_power;
	Polynomial first_pol(h_power);
	cout << "Second polynomial: \t";
	cin >> h_power;
	Polynomial second_pol(h_power);
	cout << "\nEnter the value of the coefficients from a to z (acc to the pattern: a*(x^n)+b*(x^n-1)+...+z*(x^0) for:\n"
		"First polynomial: \t";
	first_pol.enterPolynomial();
	cout << "Second polynomial: \t";
	second_pol.enterPolynomial();
	system("CLS");
formulas:
	cout << "\nFirst polynomial is: \t";
	first_pol.showPolynomial();
	cout << "\nSecond polynomial is: \t";
	second_pol.showPolynomial();
	cout << "\n\nSum of polynomials: \t\t";
	sumPolynomials(first_pol, second_pol).showPolynomial();
	cout << "\nSubtraction of polynomials: \t";
	subPolynomials(first_pol, second_pol).showPolynomial();
	cout << "\nProduct of polynomials : \t";
	prodPolynomials(first_pol, second_pol).showPolynomial();
	cout << "\nQuotient of polynomials: \t";
	quotPolynomials(first_pol, second_pol).showPolynomial();
	cout << endl;
menu:
	cout <<endl <<"--------------------------------------------------"
		"\n1 - Switch polynomials"
		"\n2 - Start over"
		"\n0 - Exit\n"
		"\nChoice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("CLS");
			switch_f(&first_pol, &second_pol);
			goto formulas;
		case 2:
			system("CLS");
			goto start;
		case 0: return 0;
	}
}
