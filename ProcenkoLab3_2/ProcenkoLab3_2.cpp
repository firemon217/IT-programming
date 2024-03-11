#include <iostream>
#include "Triangle.h" //Подключаем заголовочный файл с классом Triangle
#include<string>
#include"Fraction.h" //Подключаем заголовочный файл с классом Fraction

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Выберите номер задания:" << std::endl;
	int num; //Переменная выбора задания
	std::cin >> num;
	switch (num) //Выбор задания
	{
		case 1: //Задание: для всех вариантов задач создать класс с указанными двумя полями (Поле 1, Поле 2) и тремя методами
		{
			RightTriangle triangle; //Создаем экземпляр класса, при создании вызывается конструктор
			std::cout << "Гипотенуза равна: " << triangle.GetHypotenuse() << std::endl; //Выводим гипотенузу с помощью специального метода
			break;
		}
		case 2: //Задание: создать класс с полями, указанными в индивидуальном задании (табл. 11.2, столб 2).
		{
			Fraction<double> fraction; //Создаем экземпляр класса, при создании вызывается конструктор
			std::cout << "В процентом соотношении - " << fraction.ByPercent() << "\n Сумма цифр знаменателя - " << fraction.SumNumberDenominator() << std::endl; //Выводим процентное соотношения и сумму цифр знаменателя с помощью методов
			break;
		}
		default:
		{
			std::cout << "Такого задания нет" << std::endl;
		}
	}

}
