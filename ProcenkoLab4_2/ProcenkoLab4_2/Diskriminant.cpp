#include "Diskriminant.h"
#include <iostream>
#include "Function.h"

using namespace std;

Diskriminant::Diskriminant() //�����������
{
	this->name = "ax^2 + bx + c";
}

void Diskriminant::Calculate() //�����������
{
	cout << "��������� ����: y = " << name << endl; //��������� ����������� � �������� �
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� c: ";
	cin >> c;
	cout << "������� x: ";
	cin >> x;
	cout << "y = " << a * x * x + b * x + c << endl; //����� ����������
}

const string& Diskriminant::GetName() //���������� ���
{
	return name;
}

Diskriminant f_dis;