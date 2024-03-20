#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"

using namespace std;

vector<Function*> funcList{ &f_exp, &f_line };

int main()
{
    setlocale(LC_ALL, "rus");
    Menu menu(funcList);
    while (Function* pObject = menu.SelectObject())
    {
        pObject->Calculate();
    }
    cout << "Hello World!\n";
}

