#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int Rim(char let)
{
    if (let == 'M')
    {
        return 1000;
    }
    if (let == 'D')
    {
        return 500;
    }
    if (let == 'C')
    {
        return 100;
    }
    if (let == 'L')
    {
        return 50;
    }
    if (let == 'X')
    {
        return 10;
    }
    if (let == 'V')
    {
        return 5;
    }
    if (let == 'I')
    {
        return 1;
    }
    return 0;
}

void In(char* print, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> *(print + i);
    }
}

void Out(char* print, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(print + i);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cout << "Введите номер задания: ";
    cin >> number;
    switch (number)
    {
    case 1:
    {
        int n;
        cout << "Введите количество элементов массива: ";
        cin >> n;
        char* word = new char(n + 1);
        In(word, n);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(word + i) == 'r' || *(word + i) == 't' || *(word + i) == 'k')
            {
                count += 1;
            }
        }
        cout << "Количество символов r, k, t: " << count << endl;
        break;
    }
    case 2:
    {
        int n;
        cout << "Введите количество элементов массива: ";
        cin >> n;
        char* word = new char(n + 1);
        In(word, n);
        int countPoint = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(word + i) == '.')
            {
                countPoint += 1;
            }
        }
        char* newWord = new char(n + 1 + countPoint * 2);
        int newn = n + countPoint * 2;
        int ne = 0;
        for (int i = 0; i < n; i++)
        {
            *(newWord + i + ne) = *(word + i);
            if (*(word + i) == '.')
            {
                *(newWord + i + ne + 1) = '.';
                *(newWord + i + ne + 2) = '.';
                ne += 2;
            }
        }
        Out(newWord, newn);
        break;
    }
    case 3:
    {
        int n;
        cout << "Введите количество элементов массива: ";
        cin >> n;
        char* word = new char(n + 1);
        char* mas = new char(n + 1);
        In(word, n);
        int skip;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            skip = 0;
            for (int j = 0; j < n; j++)
            {
                if (*(word + i) == *(mas + j))
                {
                    count += 1;
                    skip = 1;
                    break;
                }
            }
            if (!skip)
            {
                *(mas + count) = *(word + i);
            }
        }
        cout << "Количество различных символов: " << n - count << endl;
        break;
    }
    case 4:
    {
        int n;
        cout << "Введите количество элементов массива: ";
        cin >> n;
        char* word = new char(n + 1);
        In(word, n);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (Rim(*(word + i)) >= Rim(*(word + i + 1)))
            {
                sum += Rim(*(word + i));
            }
            else
            {
                sum -= Rim(*(word + i));
            }
        }
        sum += Rim(*(word + n - 1));
        cout << "Переведенное число равно: " << sum << endl;
        break;
    }
    case 5:
    {
        cout << "Введите строку:" << endl;
        string word;
        cin.ignore();
        getline(cin, word);
        for (int i = 0; i < (int)word.length(); i++)
        {
            if (word[i] == ' ')
            {
                word.erase(i, 1);
            }
        }
        cout << "Итоговая строка: \n" << word << endl;
        break;
    }
    case 6:
    {
        cout << "Введите строку:" << endl;
        string word;
        cin.ignore();
        getline(cin, word);
        string reword;
        reword = word;
        int n = word.length();
        for (int i = n; i >= 0; i--)
        {
            cout << word[i];
        }
        break;
    }
    case 7:
    {
        cout << "Введите строку:" << endl;
        string sent;
        cin.ignore();
        getline(cin, sent);
        vector<string> word;
        stringstream ss(sent);
        while (ss >> sent)
        {
            word.push_back(sent);
        }
        for (string elem : word)
        {
            cout << elem << endl;
        }
        break;
    }
    default:
    {
        cout << "" << endl;
    }
    }
    return 0;
}


