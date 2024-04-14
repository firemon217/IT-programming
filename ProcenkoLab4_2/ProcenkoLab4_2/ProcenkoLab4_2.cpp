#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"
#include "Diskriminant.h"
#include "MenuFile.h"

using namespace std;

vector<Function*> funcList{ &f_exp, &f_line, &f_dis }; //Список команд в меню

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Выберете номер задания: " << endl;
    int number; //Выбор номера задания
    cin >> number;
    switch(number)
    {
        case 1:
        {
            Menu menu(funcList); //Вызов класса меню
            while (Function* pObject = menu.SelectObject()) //Проверка на выбор функции
            {
                pObject->Calculate(); //Вызов калькулятора функции
            }
            break;
        }
        case 2: 
        {
            MenuFile menu; //Вызов класса меню
            int number = 0;
            while (!number) //Выбор номера действия
            {
                number = menu.ChoiceFunc(); //Выбор функции
            }
            break;
        }
        default:
        {
            return 1;
        }
    }
}

