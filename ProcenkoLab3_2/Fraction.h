#pragma once
#include <iostream>

template <typename T>
class Fraction
{
public:
	Fraction();
	double ByPercent();
	int SumNumberDenominator();
	~Fraction()
	{
		std::cout << "Объект удален" << std::endl;
	}
private:
	T numerator;
	T denominator;
};