#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "Windows.h"

using namespace std;

void In(map<string, string>& dict, string key, string word) //Функция, для ввода значения в словарь
{
    dict.insert({ key, word });
}

void OutAll(map<string, string>& dict) //Выводит все значения из словаря
{
    for (pair<string, string> n : dict)
    {
        cout << n.first << " : " << n.second << endl;
    }
}

void OutForKey(map<string, string>& dict, string key) //Поиск по ключу
{
    cout << key << " : " << dict[key] << endl;
}

void PrintFile(map<string, string>& dict, string type) //Запись из словаря в файл
{
    fstream txt = fstream(type, ios::out | ios::binary); //Открываем файл в режиме бинарной записи
    for (pair<string, string> n : dict) //Перебираем словарь 
    {
        txt << n.first << " : " << n.second << "\n"; //Вводим значения в словарь 
    }
}

void OutFile(map<string, string>& dict, string type) //Запись из файла в словарь
{
    fstream txt = fstream(type, ios::in | ios::binary); //Открываем в режиме бинарного чтения
    string str;
    cin.ignore();
    string key = ""; //Ключь
    string word = ""; //Значение
    bool slice = false; //Переход
    while (getline(txt, str, '\n')) //Разбиваем текст на строки
    {
        for (char n : str) //Фильтрация строк
        {
            if (n == ' ')
            {
                continue;
            }
            if (n == '\n')
            {
                break;
            }
            if (slice)
            {
                word += n;
                continue;
            }
            if (n == ':')
            {
                slice = true;
                continue;
            }
            key += n;
        }
        slice = false;
        dict.insert({ key, word }); //Вводим значения в словарь
        key = "";
        word = "";
    }
}

int main()
{
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    cout << "1. Ang|Rus \n2. Rus|Ang" << endl;
    int choice;
    cin >> choice;
    map<string, string> dict = {
        
    };
    switch (choice) //Выбор словаря
    {
        case 1:
        {
            OutFile(dict, "AngRus.txt"); //Выносим текст из файла в словарь
            bool work = true;
            while (work) //Цикл работы программы
            {
                cout << "1. Print in dictionary \n2. Out all content \n3. Find necessary word \n4. Exit" << endl;
                int number;
                cin >> number;
                switch (number) //Выбор действия
                {
                    case 1:
                    {
                        cout << "Enter english word and russian translate" << endl;
                        string key, word; //Ключь - значение
                        cin >> key >> word;
                        In(dict, key, word); //Вводим значения в словарь
                        break;
                    }
                    case 2: //Выводим все из словаря
                    {
                        cout << "All word" << endl;
                        OutAll(dict);
                        break;
                    }
                    case 3: //Поиск по ключу
                    {
                        cout << "Enter necessary word" << endl;
                        string key; //Ключ
                        cin >> key;
                        OutForKey(dict, key);
                        break;
                    }
                    case 4: //Выход из программы
                    {
                        cout << "Good Bay" << endl;
                        work = false;
                        break;
                    }
                    default:
                    {
                        cout << "Error" << endl;
                    }
                }
            }
            PrintFile(dict, "AngRus.txt"); //Переписываем все значения в файл
            break;
        }
        case 2:
        {
            OutFile(dict, "RusAng.txt"); //Выносим текст из файла в словарь
            bool work = true;
            while (work) //Цикл работы программы
            {
                cout << "1. Print in dictionary \n2. Out all content \n3. Find necessary word \n4. Exit" << endl;
                int number;
                cin >> number;
                switch (number) //Выбор действия
                {
                case 1:
                {
                    cout << "Enter russian word and english translate" << endl;
                    string key, word; //Ключь - значение
                    cin >> key >> word;
                    In(dict, key, word); //Вводим значения в словарь
                    break;
                }
                case 2: //Выводим все из словаря
                {
                    cout << "All word" << endl;
                    OutAll(dict);
                    break;
                }
                case 3: //Поиск по ключу
                {
                    cout << "Enter necessary word" << endl;
                    string key; //Ключ
                    cin >> key;
                    OutForKey(dict, key);
                    break;
                }
                case 4: //Выход из программы
                {
                    cout << "Good Bay" << endl;
                    work = false;
                    break;
                }
                default:
                {
                    cout << "Error" << endl;
                }
                }
            }
            PrintFile(dict, "RusAng.txt"); //Переписываем все значения в файл
            break;
        }
        default:
        {
            cout << "Error" << endl;
        }
    }
}
