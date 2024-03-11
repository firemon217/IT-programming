#include "Fraction.h" //Определяем методы класса из заголовочного файла
#include <iostream>
#include <string>

Fraction<double>::Fraction() //Конструктор, записывающий в объект числитель и знаменатель (для дробных значений)
{
	double denominator;
	double numerator;
	std::cout << "Введите числитель: " << std::endl;
	std::cin >> numerator;
	std::cout << "Введите знаменатель: " << std::endl;
	std::cin >> denominator;
	this->denominator = denominator;
	this->numerator = numerator;
}

Fraction<int>::Fraction() //Конструктор, записывающий в объект числитель и знаменатель (для целых значений)
{
	int denominator;
	int numerator;
	std::cout << "Введите числитель: " << std::endl;
	std::cin >> numerator;
	std::cout << "Введите знаменатель: " << std::endl;
	std::cin >> denominator;
	this->denominator = denominator;
	this->numerator = numerator;
}

double Fraction<double>::ByPercent()//Высчитывает процентное соотношение дроби (для дробных значений)
{
	return (this->numerator / this->denominator) * 100;
}

double Fraction<int>::ByPercent()//Высчитывает процентное соотношение дроби (для целых значений)
{
	return (this->numerator / (double)this->denominator) * 100;
}

int Fraction<double>::SumNumberDenominator() //Суммирует цифры знаменателя (для дробных значений)
{
	std::string num;
	num = std::to_string(this->denominator); //Переводит в строковый формат
	int sum = 0;
	for (int i = 0; i < num.size(); i++) //Разбиваем строку на цифры
	{

		if (num[i] == ',' || num[i] == '.') //Игнорируем точку
		{
			continue;
		}
		sum += num[i] - '0'; //Суммируем
	}
	return sum;
}

int Fraction<int>::SumNumberDenominator() //Суммирует цифры знаменателя (для целых значений)
{
	std::string num;
	num = std::to_string(this->denominator); //Переводит в строковый формат
	int sum = 0;
	for (int i = 0; i < num.size(); i++) //Разбиваем строку на цифры
	{
		sum += (int)(num[i]); //Суммируем
	}
	return sum;
}