#pragma once
#include "Function.h"

class Exp : public Function
{
	public:
		Exp();
		const std::string& GetName();
		void Calculate();
	protected:
		std::string name;
};

extern Exp f_exp;