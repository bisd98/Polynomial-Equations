#include <iostream>
#include "Polynomial.h"

using namespace std;


Polynomial sumPolynomials(Polynomial fisrt, Polynomial second)
{
	int greater_power = 0;
	if (fisrt.power > second.power) greater_power = fisrt.power;
	else greater_power = second.power;
	Polynomial sum_result(greater_power);
	if (fisrt.power == greater_power) {
		while (greater_power > second.power)
		{
			sum_result.values[greater_power] = fisrt.values[greater_power];
			greater_power--;
		}
	}
	else {
		while (greater_power > fisrt.power)
		{
			sum_result.values[greater_power] = second.values[greater_power];
			greater_power--;
		}
	}
	while (greater_power >= 0)
	{
		sum_result.values[greater_power] = (fisrt.values[greater_power] + second.values[greater_power]);
		greater_power--;
	}
	return sum_result;
}
Polynomial subPolynomials(Polynomial fisrt, Polynomial second)
{
	int power_diff = 0;
	if (fisrt.power == second.power)
	{
		int i = fisrt.power;
		while ((fisrt.values[i] == second.values[i])&&i>0)
		{
			power_diff++;
			i--;
		}
		Polynomial sub_result((fisrt.power) - (power_diff));
		while (i>=0)
		{
			sub_result.values[i]= fisrt.values[i]- second.values[i];
			i--;
		}
		return sub_result;
	}
	else if (fisrt.power > second.power)
	{
		Polynomial sub_result(fisrt.power);
		int i = fisrt.power;
		while (i != second.power)
		{
			sub_result.values[i] = fisrt.values[i];
			i--;
		}
		while (i >= 0)
		{
			sub_result.values[i] = (fisrt.values[i] - second.values[i]);
			i--;
		}
		return sub_result;
	}
	else if (fisrt.power < second.power)
	{
		Polynomial sub_result(second.power);
		int i = second.power;
		while (i != fisrt.power)
		{
			sub_result.values[i] = (-1)*(second.values[i]);
			i--;
		}
		while (i >= 0)
		{
			sub_result.values[i]= (fisrt.values[i] - second.values[i]);
			i--;
		}
		return sub_result;
	}
}

Polynomial prodPolynomials(Polynomial fisrt, Polynomial second)
{
	int power_sum = (fisrt.power + second.power);
	Polynomial pord_result(power_sum);
	for (int i = fisrt.power;i >= 0;i--)
	{
		for (int j = second.power;j >= 0;j--)
		{
			pord_result.values[i + j] += fisrt.values[i] * second.values[j];
		}
	}
	return pord_result;
}

Polynomial quotPolynomials(Polynomial fisrt, Polynomial second)
{
	int power_diff = ((fisrt.power)- (second.power));
	Polynomial quot_result(power_diff);
	Polynomial aux_func_1 = fisrt;
	float rest = 0;
	while(!((aux_func_1.power==0)&& (aux_func_1.values[0] == 0)))
	{
		Polynomial aux_multiplier((aux_func_1.power) - second.power);
		float mnoznik = (aux_func_1.values[aux_func_1.power] / second.values[second.power]);
		quot_result.values[aux_multiplier.power] = mnoznik;
		aux_multiplier.values[aux_multiplier.power] = mnoznik;
		Polynomial aux_func_2 = prodPolynomials(aux_multiplier, second);
		aux_func_1 = subPolynomials(aux_func_1, aux_func_2);
		if ((aux_func_1.power < second.power))
		{
			int i = aux_func_1.power;
			cout << "(rest= ";
			while (i >= 0)
			{
				rest = aux_func_1.values[i];
				cout << rest;
				if (i > 0)
				{
					cout << "x";
					if(i>1) cout<<"^"<< i;
				}
				if (aux_func_1.values[i - 1] > 0)cout << '+';
				i--;
			}
			cout<< ") ";
			return quot_result;
		}
	}
	return quot_result;
}
