#include "CMyData.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void CMyData::Open() //�������� �����
{
	string name; //�������� �� ���� ��� �����
	cin >> name;
	f_myData.SetName(name); //������������� ��� ����� ����������� ���������� ������
	MyData.open(name, ios::app | ios::in | ios::binary); //��������� ���� � ������ ��������� ������ � ������
}

void CMyData::Close() //��������� ����
{
	MyData.close();
}

void CMyData::Read() //��������� ������ �����
{
	string buf;
	getline(MyData, buf); //������������ �������� �� ����� � ���������� ���������
	cout << buf << endl;
	MyData.close(); //������������� ����
	MyData.open(name, ios::app | ios::in | ios::binary);
}

void CMyData::Write() //���������� � ����
{
	string let;
	cout << "���� ������ � ����: " << endl;
	cin.ignore();
	getline(cin, let); //���������� ������� � ����������
	MyData << let; //��������� �� � ����
	MyData.close(); //������������� ����
	MyData.open(name, ios::app | ios::in | ios::binary);
}

void CMyData::GetPosition()
{
	int point = MyData.tellg();
	cout << point << endl;
}

void CMyData::GetLength() //�������� ����� ����
{
	int point = MyData.tellg();
	MyData.seekg(0, ios::end); //��������� � ����� ����
	int length = MyData.tellg(); //�������� �����
	MyData.seekg(0, point); //���������� � �������� �����
	cout << length << endl;
}

void CMyData::Seek()
{

}

void CMyData::SetName(string name) //������������� ���
{
	this->name = name;
}

CMyData f_myData;