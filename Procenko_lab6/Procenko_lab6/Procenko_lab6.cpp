#include <iostream>

using namespace std;

template<typename T>
void In(T pn, int n)
{
    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> *(pn + i);
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cout << "Введите номер задания:" << endl;
    cin >> number;
    switch (number)
    {
        case 1:
        {
            char a, b;
            cout << "Введите 2 символа:" << endl;
            cin >> a >> b;
            char* pa = &a;
            char* pb = &b;
            cout << "a: " << *pa << " b: " << *pb << endl;
            char* pt = pa;
            pa = pb;
            pb = pt;
            cout << "a: " << *pa << " b: " << *pb << endl;
            break;
        }
        case 2:
        {
            bool* pa = new bool;
            bool* pb = new bool;
            *pa = true;
            *pb = false;
            cout << "a: " << *pa << " b: " << *pb << endl;
            bool* pt = pa;
            pa = pb;
            pb = pt;
            cout << "a: " << *pa << " b: " << *pb << endl;
            break;
        }
        case 3:
        {
            int n;
            int m;
            cout << "Введите количество элементов массивов x и y:" << endl;
            cin >> n >> m;
            int* px = new int[n];
            int* py = new int[m];
            In(px, n);
            In(py, m);
            int count = 0;
            for (int i = 0; i < m; i++)
            {
                if (*(py + i) == *(px + n - 1))
                {
                    count += 1;
                }
            }
            cout << "Последний элемент массива x встречается в массиве y " << count << " раз." << endl;
            break;
        }
        case 4:
        {
            int n;
            cout << "Введите количество элементов массива:" << endl;
            cin >> n;
            int* pf = new int[n];
            int* px = new int[n];
            In(pf, n);
            for (int i = 0; i < n; i++)
            {
                if (*(pf + i) == 0)
                {
                    continue;
                    *(px + i) = 0;
                }
                *(px + i) = *(pf + i) * *(pf + i);
            }
            int count;
            while(true)
            {
                count = 0;
                for (int j = 1; j < n; j++)
                {
                    if (*(px + j - 1) <= *(px + j))
                    {
                        continue;
                    }
                    count += 1;
                    int temp = *(px + j - 1);
                    *(px + j - 1) = *(px + j);
                    *(px + j) = temp;
                }
                if (count == 0)
                {
                    break;
                }
            }
            cout << "Массив:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << *(px + j) << "   ";
            }
            delete[] pf;
            delete[] px;
            break;
        }
        default:
        {
            cout << "Такого задания нет" << endl;
        }
    }
    
}