#include"MyQueue.h"

template<typename T>
void MyQueue<T>::Menu() //�������������� �������� � ������������ � ���� ����
{
	bool go = true;
	while (go)
	{
		cout << "1. Push \n2. Del \n3. Show" << endl; //����� ������
		int number;
		cin >> number;
		switch (number)
		{ 
			case 1: //��������� �������
			{
				T elem;
				try //��������� �� ������ ���
				{
					cout << "Enter element" << endl;
					cin >> elem;
				}
				catch (T i)
				{
					cout << "Error" << endl;
					go = false;
					break;
				}
				Push(elem);
				break;
			}
			case 2: //������� �������
			{
				cout << "Element was deleted" << endl;
				Del();
				break;
			}
			case 3: //�������� ��������
			{
				cout << "Your elements" << endl;
				Show();
				break;
			}
			default:
			{
				cout << "Nothing" << endl;
				go = false;
			}
		}
	}
}

template<typename T>
void MyQueue<T>::Push(T elem) //���������� Push
{
	queue.push_back(elem); //��������� � ��� ���������-���� �������
}

template<typename T>
void MyQueue<T>::Del() //���������� Del
{
	queue.pop_front(); //������� ������� �� ����
}

template<typename T>
void MyQueue<T>::Show() //���������� Show
{
	for (T elem : queue) //���������� �������� ����
	{
		cout << elem << " "; //�����
	}
	cout << endl;
}