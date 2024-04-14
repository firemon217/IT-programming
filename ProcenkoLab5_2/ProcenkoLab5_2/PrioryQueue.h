#pragma once
#include"string"

using namespace std;

template<typename Data> //��������� ����� ������� � �����������
class PrioryQueue
{
	class Node //������� �������
	{
		public:
			Data data; //�������� ��������
			Node* prev; //��������� �� ���������� �������
			Node* next; //��������� �� ��������� �������
			Node(Data dat = 0) //�����������
			{
				data = dat;
				next = prev = 0;
			}
	};
	Node* pbegin; //��������� �� ������ ������� �������
	Node* pend; //��������� �� ��������� ������� �������
	public:
		void Add(Data dat) //��������� ������� � �������
		{
			Node* pelem = new Node(dat); //����� �������
			if (pbegin == pend == 0) //���� ��������� ��� ���
			{
				pbegin = pend = pelem;
			}
			else //���� �������� ��� ����
			{
				pelem->prev = pend; 
				pend->next = pelem;
				pend = pelem;
			}
		};
		PrioryQueue() { pbegin = 0; pend = 0; }; //�����������
		void Remove() //�������� �������� �� ������� (������� ����� ������� �������)
		{
			Node* pelem = pbegin; 
			int maxim = -1000000000; //������������ ��������
			while (pelem) //���������� ��������
			{
				if (maxim < pelem->data) //���� ������������ ������� �������
				{
					maxim = pelem->data;
				}
				pelem = pelem->next;
			}
			pelem = pbegin;
			while (pelem) //���������� ��������
			{
				if (pelem->data == maxim) //���� ������� �������/� - ������� ���
				{
					(pelem->prev)->next = pelem->next;
					(pelem->next)->prev = pelem->prev;
				}
				pelem = pelem->next;
			}
			delete pelem;
		};
		Node* Find(Data key) //������� ������� �� ��������
		{
			Node* pelem = pbegin;
			while (pelem) //���������� ��������
			{
				if (pelem->data == key) //���� �������, ������� �� ��������
				{
					break;
				}
				pelem = pelem->next;
			}
			return pelem; //���������� �������
		};
		void Print() //������������ �������
		{
			Node* pelem = pbegin;
			cout << "Queue: " << endl;
			while (pelem) //���������� �������� � ������� ��
			{
				cout << pelem->data << ' ';
				pelem=pelem->next;
			}
			cout << endl;
		};
};