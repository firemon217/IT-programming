#include "Triangle.h" //���������� ������ ������ �� ������������� �����
#include "math.h"
#include <iostream>

RightTriangle::RightTriangle() //�����������, ������������ ������ ������������-�������
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

double RightTriangle::GetlegH() //�������� 1 �����
{
	return this->legH;
}

double RightTriangle::GetlegW() //�������� 2 �����
{
	return this->legW;
}

void RightTriangle::SetlegH(double legH) //������������� �������� 1 ������
{
	this->legH = legH;
}

void RightTriangle::SetlegW(double legW) //������������� �������� 2 ������
{
	this->legW = legW;
}

double RightTriangle::GetHypotenuse() //�������� ���������� ������������
{
	return sqrt(pow(this->legH, 2) + pow(this->legW, 2)); //������� ��������
}