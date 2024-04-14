#pragma once
#include "Function.h"
#include <vector>

class Menu //����� ���� �������
{
	public: 
		Menu(std::vector<Function*>); //�����������
		Function* SelectObject(); // ����� �������
	private:
		int SelectItem(int);
		std::vector<Function*> pObject;
};