#pragma once
#include<iostream>
#include<List>

using namespace std;

template <typename T>
class MyQueue
{
	list<T> queue; //����-��������� �� ������� �������
	public:
		void Menu(); //����
		void Push(T elem); //�������� �������
		void Del(); //������� �������
		void Show(); //������� ��������
};