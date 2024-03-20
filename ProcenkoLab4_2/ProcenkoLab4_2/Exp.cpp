#include "Exp.h"
#include "math.h"
#include <iostream>
#include <string>

using namespace std;

void Exp::Calculate()
{
	cout << "”равнение вида: y = " << name << endl;
	cout << "¬ведите x: ";
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