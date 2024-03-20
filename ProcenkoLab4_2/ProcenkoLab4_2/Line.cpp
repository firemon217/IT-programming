#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

void Line::Calculate()
{
	cout << "”равнение вида: y = " << name << endl;
	cout << "¬ведите a: ";
	cin >> a;
	cout << "¬ведите b: ";
	cin >> b;
	cout << "¬ведите x: ";
	cin >> x;
	cout << "y = " << a*x + b << endl;
}

Line::Line()
{
	this->name = "ax + b";
}

const string& Line::GetName()
{
	return name;
}

Line f_line;