#include "Exp.h"
#include "math.h"
#include <iostream>
#include <string>

using namespace std;

void Exp::Calculate()
{
	cout << "��������� ����: y = " << name << endl;
	cout << "������� x: ";
	cin >> x;
	cout << "y = " << exp(x) << endl;
}

Exp::Exp()
{
	this->name = "e ^ x";
}

const string& Exp::GetName()
{
	return name;
}

Exp f_exp;