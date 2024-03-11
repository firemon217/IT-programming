#include "Fraction.h" //���������� ������ ������ �� ������������� �����
#include <iostream>
#include <string>

Fraction<double>::Fraction() //�����������, ������������ � ������ ��������� � ����������� (��� ������� ��������)
{
	double denominator;
	double numerator;
	std::cout << "������� ���������: " << std::endl;
	std::cin >> numerator;
	std::cout << "������� �����������: " << std::endl;
	std::cin >> denominator;
	this->denominator = denominator;
	this->numerator = numerator;
}

Fraction<int>::Fraction() //�����������, ������������ � ������ ��������� � ����������� (��� ����� ��������)
{
	int denominator;
	int numerator;
	std::cout << "������� ���������: " << std::endl;
	std::cin >> numerator;
	std::cout << "������� �����������: " << std::endl;
	std::cin >> denominator;
	this->denominator = denominator;
	this->numerator = numerator;
}

double Fraction<double>::ByPercent()//����������� ���������� ����������� ����� (��� ������� ��������)
{
	return (this->numerator / this->denominator) * 100;
}

double Fraction<int>::ByPercent()//����������� ���������� ����������� ����� (��� ����� ��������)
{
	return (this->numerator / (double)this->denominator) * 100;
}

int Fraction<double>::SumNumberDenominator() //��������� ����� ����������� (��� ������� ��������)
{
	std::string num;
	num = std::to_string(this->denominator); //��������� � ��������� ������
	int sum = 0;
	for (int i = 0; i < num.size(); i++) //��������� ������ �� �����
	{

		if (num[i] == ',' || num[i] == '.') //���������� �����
		{
			continue;
		}
		sum += num[i] - '0'; //���������
	}
	return sum;
}

int Fraction<int>::SumNumberDenominator() //��������� ����� ����������� (��� ����� ��������)
{
	std::string num;
	num = std::to_string(this->denominator); //��������� � ��������� ������
	int sum = 0;
	for (int i = 0; i < num.size(); i++) //��������� ������ �� �����
	{
		sum += (int)(num[i]); //���������
	}
	return sum;
}