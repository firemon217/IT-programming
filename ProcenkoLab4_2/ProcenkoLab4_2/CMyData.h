#pragma once
#include <iostream>
#include "CFile.h"
#include <string>
#include <fstream>

class CMyData : public CFile //�������� �����, ����������� �� �������� �����
{
	public:
		void Open(); //���������� ������� ����������
		void Close();
		void Seek();
		void Read();
		void Write();
		void GetPosition();
		void GetLength();
		std::fstream& GetMyData() //���������� ���������� �����
		{
			return MyData; 
		}
		void SetName(std::string name); //������������� ��� �����
	private:
		std::fstream MyData; //����
		std::string name; //��� �����
};

extern CMyData f_myData; //��������� �����