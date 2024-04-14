#pragma once
#include "Function.h"
#include <string>

class Diskriminant : public Function
{
public:
	Diskriminant(); //�����������
	const std::string& GetName();
	void Calculate(); //����������� �������
protected:
	std::string name; //��� �������
	double a; //����������
	double b;
	double c;
};

extern Diskriminant f_dis;