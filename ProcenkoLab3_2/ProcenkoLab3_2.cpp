#include <iostream>
#include "Triangle.h"
#include<string>
#include"Fraction.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
		case 1:
		{
			RightTriangle triangle;
			std::cout << "Гипотенуза равна: " << triangle.GetHypotenuse() << std::endl;
			break;
		}
		case 2:
		{
			Fraction<double> fraction;
			std::cout << "В процентом соотношении - " << fraction.ByPercent() << "\n Сумма цифр знаменателя - " << fraction.SumNumberDenominator() << std::endl;
			break;
		}
		default:
		{

		}
	}

}
