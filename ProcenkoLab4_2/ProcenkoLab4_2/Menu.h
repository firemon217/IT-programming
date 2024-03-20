#pragma once
#include "Function.h"
#include <vector>

class Menu : public Function
{
	public:
		const std::string& GetName() { return "1"; };
		void Calculate() {};
		Menu(std::vector<Function*>);
		Function* SelectObject();
	private:
		int SelectItem(int);
		std::vector<Function*> pObject;
};