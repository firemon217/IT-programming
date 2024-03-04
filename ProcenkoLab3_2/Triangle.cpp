#include "Triangle.h"
#include "math.h"
#include <iostream>

RightTriangle::RightTriangle()
{
	double legH;
	double legW;
	std::cout << "������� 1 �����" << std::endl;
	std::cin >> legH;
	std::cout << "������� 2 �����" << std::endl;
	std::cin >> legW;
	this->legW = legW;
	this->legH = legH;
}

double RightTriangle::GetlegH()
{
	return this->legH;
}

double RightTriangle::GetlegW()
{
	return this->legW;
}

void RightTriangle::SetlegH(double legH)
{
	this->legH = legH;
}

void RightTriangle::SetlegW(double legW)
{
	this->legW = legW;
}

double RightTriangle::GetHypotenuse()
{
	return sqrt(pow(this->legH, 2) + pow(this->legW, 2));
}