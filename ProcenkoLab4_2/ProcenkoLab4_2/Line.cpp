#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

void Line::Calculate() //�����������
{
	cout << "��������� ����: y = " << name << endl; //��������� �������� �
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� x: ";
	cin >> x;
	cout << "y = " << a*x + b << endl; //����� ����������
}

Line::Line() //�����������
{
	this->name = "ax + b";
}

const string& Line::GetName() //���������� ���
{
	return name;
}

Line f_line;