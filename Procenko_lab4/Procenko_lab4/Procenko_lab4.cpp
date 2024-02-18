#include<iostream>
#include<math.h>

using namespace std;

template <typename T> T Pow(T n, int s); //Прототипы функций
int Fact(int n);

double Sum1_1(int n) //Функция, подсчитыывающая сумму ряда первых n членов по определенной формуле
{
    double sum{ 0 }; //Сумма ряда
    for (int i = 0; i <= n; i++) //Перебирает все слагаемые суммы
    {
        sum += (i + 1.) / (pow(i, 3) + 1.); //Прибавляем каждое слагаемое к сумме
    }
    return sum; //Возвращаем сумму
}

double Sum1_2__1(int n) //Функция, подсчитыывающая сумму ряда первых n членов по определенной формуле
{
    double sum{ 0 }; //Сумма ряда
    for (double i = 2; i <= n; i++) //Перебирает все слагаемые суммы
    {
        sum += Pow(-1, (int)i) * ((i + 2)/(Pow(i, 3) + i - 2)); //Прибавляем каждое слагаемое к сумме
    }
    return sum; //Возвращаем сумму
}

double Sum1_2__2(double eps) //Функция, подсчитыывающая сумму ряда первых n членов по определенной формуле с точностью до эпсилон
{
    double sum{ 0 }; //Сумма ряда
    double sumnow{ 0 }; //Нынешнее слагаемое
    double sumprev{ 0 }; //Предыдущие слагаемое
    double i{ 2 }; //Из-за ограничений в i != 1 начинаем перебирать натуральные значения с 2
    do //Считываем сумму ряда, пока не достигним нужной точности
    {
        sum += Pow(-1, (int)i) * ((i + 2) / (Pow(i, 3) + i - 2)); //Считывает сумму ряда
        sumnow = Pow(-1, (int)i) * ((i + 2) / (Pow(i, 3) + i - 2)); //Высчитывает нынешнее слагаемое
        i++;
    } while (abs(abs(sumnow) - abs(sumprev)) > eps); //Проверяем точность ряда
    sumprev = sumnow; //Запоминаем прошлое слагаемое
    return sum; //Возвращеам сумму
}

double Sum1_3__1(double x, int n) //Функция, подсчитыывающая сумму ряда первых n членов по определенной формуле с введеной переменной от пользователя
{
    double sum{ 0 }; //Сумма ряда
    for (int i = 1; i <= n; i++) //Высчитывает сумму ряда
    {
        sum += x * (Pow(-1, i) * (Pow(2., i) / (Pow(3., i + 1) * Fact(i + 1)))); //Прибавляем слагаемое к ряду
    }
    return sum; //Возвращаем сумму
}

double Sum1_3__2(double x, double eps) //Функция, подсчитыывающая сумму ряда первых n членов по определенной формуле с точность до эпсилон с введеной переменной от пользователя
{
    double sum{ 0 }; //Сумма ряда
    double sumnow{ 0 }; //Нынешнее слагаемое
    double sumprev{ 0 }; //Предыдущие слагаемое
    int i{ 1 }; //Начальное значение ряда
    do //Считываем сумму ряда, пока не достигнем нужной точности
    {
        sum += x * (Pow(-1, i) * (Pow(2., i) / (Pow(3., i + 1) * Fact(i + 1)))); //Прибавляем слагаемое к ряду
        sumnow = x * (Pow(-1, i) * (Pow(2., i) / (Pow(3., i + 1) * Fact(i + 1)))); //Вычисляем нынешнее слагаемое
        i++; //Переходим к следующему слагаемуму
    } while (abs(abs(sumnow) - abs(sumprev)) > eps); //Проверяем точность
    sumprev = sumnow; //Запоминанем прошлое слагаемое
    return sum; //Возвращаем сумму
}

int Prove(int n) //Проверяем число на количество цифр
{
    int count{ 1 }; //Количество цифр
    while (n > 0)
    {
        n /= 10; //Делим число на 10
        if (n == 0) //Проверка на конец преобразований
        {
            break;
        }
        count += 1; //Считываем количество цифр
    }
    return count; //Возвращаем количество цифр
}

bool Prost(int n, int count) //Проверка на простоту суммы цифр числа
{
    int sum{ 0 }; //Сумма цифр числа
    for (int i = 10; i <= pow(10, count); i *= 10) //Разделяет число на цифры
    {
        sum += (abs(n) % i) / (i / 10); //Вычисляет сумму цифр числа
    }
    for (int j = 2; j <= sqrt(sum); j++) //Проверяем на простоту, начиная с 4
    {
        if (sum % j == 0) //Если число делиться на что-то, кроме себя самого
        {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "rus"); 
    int number; //Номер задания
    cout << "Введите номер задания" << endl;
    cin >> number; //Ввод номера задания
    switch (number) //Выбираем нужный номер
    {
        case 1: //1.1
        {
            int n;
            cout << "Введите число" << endl;
            cin >> n;
            cout << "Сумма равна: " << Sum1_1(n) << endl;
            break;
        }
        case 2: //1.2
        {
            int n;
            double eps;
            cout << "Введите число" << endl;
            cin >> n;
            cout << "Введите число" << endl;
            cin >> eps;
            cout << "Сумма равна: " << Sum1_2__1(n) << endl;
            cout << "Сумма равна: " << Sum1_2__2(eps) << endl;
            break;
        }
        case 3: //2.1
        {
            int n;
            double eps;
            double x;
            cout << "Введите число" << endl;
            cin >> n;
            cout << "Введите x" << endl;
            cin >> x;
            cout << "Введите число" << endl;
            cin >> eps;
            cout << "Сумма равна: " << Sum1_3__1(x, n) << endl;
            cout << "Сумма равна: " << Sum1_3__2(x, eps) << endl;
            break;
        }
        case 4: //2.2
        {
            int n;
            int sum{ 0 };
            int count{ 0 };
            int num{ 0 };
            int numprev{ 0 };
            int min{ 0 };
            cout << "Введите последовательность чисел: " << endl;
            cin >> n;
            do
            {
                if (n < sum)
                {
                    count += 1;
                }
                sum += n;
                num = Prove(n);
                if (num > numprev)
                {
                    min = n;
                }
                if (num == numprev)
                {
                    if (min > n)
                    {
                        min = n;
                    }
                }
                numprev = num;
                cin >> n;
            } while (n != 0);
            cout << "Количество чисел, непревосходящих сумму всех предшествующих элементов: " << count << " Минимальное число из подходящих: " << min << endl;
            break;
        }
        case 5: //2.3
        {
            int n;
            int count{ 0 };
            int maxprost{ 0 };
            int maxneprost{ 0 };
            cout << "Введите последовательность чисел: " << endl;
            cin >> n;
            while (n != 0)
            {
                while (Prost(n, Prove(n)) && n != 0)
                {
                    count += 1;
                    cin >> n;
                }
                if (!Prost(n, Prove(n)))
                {
                    if (maxprost < count)
                    {
                        maxprost = count;
                    }
                    count = 0;
                }
                while (!Prost(n, Prove(n)) && n != 0)
                {
                    count += 1;
                    cin >> n;
                }
                if (Prost(n, Prove(n)))
                {
                    if (maxneprost < count)
                    {
                        maxneprost = count;
                    }
                    count = 0;
                }
            }
            cout << "Максимальное количество идущих подряд чисел, соответсвующие условию: " << maxprost << endl;
            cout << "Максимальное количество идущих подряд чисел, не соответсвующие условию: " << maxneprost << endl;
            break;
        }
    }
}

template <typename T>
T Pow(T n, int s)
{
    T res = 1;
    for (int i = 1; i < s; i++)
    {
        res = res*n;
    }
    return res;
}


int Fact(int n)
{
    int sum{ 1 };
    while (n > 1)
    {
        sum *= n;
        n -= 1;
    }
    return sum;
}