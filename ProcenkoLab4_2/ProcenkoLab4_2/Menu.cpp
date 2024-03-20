#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(vector<Function*> _pObject)
{
	for (Function* i : _pObject)
	{
		pObject.push_back(i);
	}
	pObject.push_back(0);
}

Function* Menu::SelectObject() 
{
	int nItem = pObject.size();
	cout << "=====================================\n";
	cout << "Select one of the following function in:\n"; 
	for (int i = 0; i < nItem; i++)
	{
		cout << i + 1 << ". ";
		if (pObject[i])
		{
			cout << pObject[i]->GetName() << endl;
		}
		else 
		{
			cout << "Exit " << endl;
		}
	}
	int item = SelectItem(nItem);
	return pObject[item - 1];
}

int Menu::SelectItem(int nItem) 
{
	cout << "-----------\n";
	int item;
	while (true)
	{
		cin >> item;
		if ((item > 0) && (item <= nItem))
		{
			break;
		}
		else
		{
			cout << "Error__" << endl;
		}
	}
	return item;
};