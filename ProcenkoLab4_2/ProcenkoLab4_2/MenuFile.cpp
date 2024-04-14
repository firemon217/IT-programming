#include <iostream>
#include <string>
#include <fstream>
#include "MenuFile.h"
#include "CMyData.h"

using namespace std;

int MenuFile::ChoiceFunc()
{
	int end = 1;
	while (end) //���� ���������� �������, �������� �����������
	{
		if (f_myData.GetMyData().is_open()) //�������� �� ��������
		{
			cout << "1. ������� \n2. ������� \n3. ����� \n4. ��������� \n5. �������� \n6. �������� ������� ������� \n7. �������� ����� �����" << endl;
			int num;
			cin >> num;
			switch (num) //����� �������
			{
				case 1:
				{
					f_myData.Open();
					break;
				}
				case 2:
				{
					f_myData.Close();
					end = 0;
					break;
				}
				case 3:
				{
					f_myData.Seek();
					break;
				}
				case 4:
				{
					f_myData.Read();
					break;
				}
				case 5:
				{
					f_myData.Write();
					break;
				}
				case 6:
				{
					f_myData.GetPosition();
					break;
				}
				case 7:
				{
					f_myData.GetLength();
					break;
				}
				default:
				{
					end = 0;
					return 1;
				}
			}
		}
		else //���� ���� ������
		{
			cout << "�������� ����: " << endl;
			f_myData.Open();
		}
	}
	return 0;
}