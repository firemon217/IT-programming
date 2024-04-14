#pragma once
#include <iostream>
#include <string>
#include <fstream>

class CFile //������� ����� ������ � �������
{
	public:
		virtual void Open() = 0; //����������� ������� �������� �����
		virtual void Close() = 0; //����������� ������� �������� �����
		virtual void Seek() = 0; //����������� ������� ������ ��������� � �����
		virtual void Read() = 0; //����������� ������� ���������� �����
		virtual void Write() = 0; //����������� ������� ������ � ����
		virtual void GetPosition() = 0; //����������� ������� �������� ������� ������� �����
		virtual void GetLength() = 0; //����������� ������� �������� ������� �����
};