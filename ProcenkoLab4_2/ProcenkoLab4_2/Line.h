#pragma once
#include "Function.h"
#include <string>

class Line : public Function
{
	public:
		Line();
		const std::string& GetName();
		void Calculate();
	protected:
		std::string name;
		double a;
		double b;
};

extern Line f_line;