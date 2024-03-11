#include "Triangle.h" //Определяем методы класса из заголовочного файла
#include "math.h"
#include <iostream>

RightTriangle::RightTriangle() //Конструктор, определяющий катеты треугольника-объекта
{
	double legH;
	double legW;
	std::cout << "Введите 1 катет" << std::endl;
	std::cin >> legH;
	std::cout << "Введите 2 катет" << std::endl;
	std::cin >> legW;
	this->legW = legW;
	this->legH = legH;
}

double RightTriangle::GetlegH() //Получаем 1 катет
{
	return this->legH;
}

double RightTriangle::GetlegW() //Получаем 2 катет
{
	return this->legW;
}

void RightTriangle::SetlegH(double legH) //Устанавливаем значение 1 катета
{
	this->legH = legH;
}

void RightTriangle::SetlegW(double legW) //Устанавливаем значение 2 катета
{
	this->legW = legW;
}

double RightTriangle::GetHypotenuse() //Получаем гипотенузу треугольника
{
	return sqrt(pow(this->legH, 2) + pow(this->legW, 2)); //Теорема Пифагора
}