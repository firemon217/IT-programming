#pragma once
#include <string>

class Function
{
	public:
		virtual const std::string& GetName() = 0;
		virtual void Calculate() = 0;
	protected:
		double x;
};