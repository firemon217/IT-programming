#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus"); // Позвоялет выводить русские символы
    cout << "-----------------------------------\nExample 1\n-----------------------------------\n\n"; // Начало 1 примера
    int year;
    cout << "Введите год:\n";
    cin >> year; // Запрашивает ввод года для проверки
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { // Проверка високосности
        cout << "YES" << endl; // Выводиться при високосном году
    }
    else {
        cout << "NO" << endl; // Выводиться, если год не високосный
    }
    cout << "\n-----------------------------------\nExample 2\n-----------------------------------\n\n"; // Начало 2 примера
    int a, b;
    cout << "Введите два числа:\n";
    cin >> a >> b;
    if (b < a) { // Проверяем, какое число меньше
        a = b; // если меньшее б, то это значение переписывается в а
    }
    cout << a << endl; // Выводиться наименьшее число
    cout << "\n-----------------------------------\nExample 3\n-----------------------------------\n\n"; // Начало 3 примера
    int c;
    cout << "Введите 3 числа" << endl;
    cin >> a >> b >> c; // Ввод чисел
    if (b < a) { // Сравнение первой пары
        a = b;
    }
    if (c < a) { // Сравнение второй пары
        a = c;
    }
    cout << a << endl; // Результат
    cout << "\n-----------------------------------\nExample 4\n-----------------------------------\n\n"; // Начало 4 примера
    int x;
    cout << "Введите число" << endl;
    cin >> x; // Ввод числа
    if (x == 1) {
        cout << "One" << endl;
    }
    else if (x == 2) {
        cout << "Two" << endl;
    }
    else if (x == 3) {
        cout << "Three" << endl;
    }
    else {
        cout << "Other" << endl;
    }

	int number, X, Y, Z, K, L, M, N, A, B, C, D, ram;
	cout << "номер задания" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
	{
		cout << "----------------------------------------\nПример 1\n----------------------------------------\n\n";
		X, Y, Z;
		Z = 0;
		cout << "Введите 2 числа, отличные от 0" << endl;
		cin >> X >> Y;
		if (Z < X)
		{
			if (Z < Y)
			{
				cout << "Его порядковое число 1" << endl;
			}
			else
			{
				cout << "Его порядковое число 2" << endl;
			}
		}
		else if (Z > X)
		{
			if (Z < Y)
			{
				cout << "Его порядковое число 2" << endl;
			}
			else
			{
				cout << "Его порядковое число 3" << endl;
			}
		}
		break;
	}
	case 2:
	{
		cout << "\n----------------------------------------\nПример 2\n----------------------------------------\n\n";
		K, L, N;
		cout << "Введите 3 различных числа" << endl;
		cin >> K >> L >> N;
		if (K < L)
		{
			if (K < N)
			{
				cout << "Наименьшее число " << K << endl;
				if (L < N)
				{
					cout << "Наибольшее число " << N << endl;
				}
				else
				{
					cout << "Наибольшее число " << L << endl;
				}
			}
			else
			{
				cout << "Наименьшее число " << N << endl;
				if (L < K)
				{
					cout << "Наибольшее число " << K << endl;
				}
				else
				{
					cout << "Наибольшее число " << L << endl;
				}
			}
		}
		else
		{
			if (L < N)
			{
				cout << "Наименьшее число " << L << endl;
				if (N < K)
				{
					cout << "Наибольшее число " << K << endl;
				}
				else
				{
					cout << "Наибольшее число " << N << endl;
				}
			}

		}
		break;
	}
	case 3:
	{
		cout << "\n----------------------------------------\nПример 3\n----------------------------------------\n\n";
		cout << "Введите 2 различных числа" << endl;
		cin >> Y >> Z;
		if (Y < Z)
		{
			A = Y;
			Y = 2 * Y * Z;
			Z = (A + Z) / 2;
			cout << "Наибольшее число Z " << Z << endl;
			cout << "Наименьшее число Y " << Y << endl;
		}
		else
		{
			A = Y;
			Y = (Y + Z) / 2;
			Z = 2 * A * Z;
			cout << "Наибольшее число Y " << Y << endl;
			cout << "Наименьшее число Z " << Z << endl;
		}
		break;
	}
	case 4:
	{
		cout << "\n----------------------------------------\nПример 4\n----------------------------------------\n\n";
		int moreZero = 0;
		int lessZero = 3;
		cout << "Введите 3 различных числа" << endl;
		cin >> X >> Y >> Z;
		if (X > 0)
		{
			moreZero += 1;
		}
		if (Y > 0)
		{
			moreZero += 1;
		}
		if (Z > 0)
		{
			moreZero += 1;
		}
		lessZero -= moreZero;
		cout << "Чисел, больше нуля: " << moreZero << endl;
		cout << "Чисел, меньше нуля: " << lessZero << endl;
		break;
	}
	case 5:
	{
		cout << "\n----------------------------------------\nПример 5\n----------------------------------------\n\n";
		cout << "Введите 3 различных числа" << endl;
		cin >> A >> B >> C;
		if (A > B)
		{
			if (A > C)
			{
				if (B < C)
				{
					cout << "Разность: " << A - B << endl;
				}
				else
				{
					cout << "Разность: " << A - C << endl;
				}
			}
			else
			{
				cout << "Разность: " << C - B << endl;
			}
		}
		else
		{
			if (A > C)
			{
				cout << "Разность: " << B - C << endl;
			}
			else
			{
				if (B > C)
				{
					cout << "Разность: " << B - A << endl;
				}
				else
				{
					cout << "Разность: " << C - A << endl;
				}
			}
		}
		break;
	}
	case 6:
	{
		cout << "\n----------------------------------------\nПример 6\n----------------------------------------\n\n";
		cout << "Введите 3 различных числа" << endl;
		cin >> K >> M >> N;
		if (K < M)
		{
			if (K < N)
			{
				if (M > N)
				{
					ram = M;
					M = N;
					N = M;
				}
			}
			else
			{
				ram = M;
				M = K;
				K = N;
				N = ram;
			}
		}
		else
		{
			if (K > N)
			{
				if (N < M)
				{
					ram = M;
					M = K;
					K = N;
					N = ram;
				}
				else
				{
					ram = M;
					M = N;
					N = K;
					K = ram;
				}
			}
			else
			{
				ram = K;
				K = M;
				M = ram;
			}
		}
		cout << "Порядок: " << K << ", " << M << ", " << N << ", " << endl;
		break;
	}
	case 7:
	{
		cout << "\n----------------------------------------\nПример 7\n----------------------------------------\n\n";
		cout << "Введите 3 различных числа" << endl;
		cin >> X >> Y >> Z;
		if (X < Y)
		{
			if (X < Z)
			{
				cout << "Два наибольших числа: " << Z << ", " << Y << endl;
			}
			else
			{
				cout << "Два наибольших числа: " << X << ", " << Y << endl;
			}
		}
		else
		{
			if (X < Z)
			{
				cout << "Два наибольших числа: " << Z << ", " << X << endl;
			}
			else
			{
				if (Z < Y)
				{
					cout << "Два наибольших числа: " << X << ", " << Y << endl;
				}
				else
				{
					cout << "Два наибольших числа: " << Z << ", " << X << endl;
				}
			}
		}
		break;
	}
	case 8:
	{
		cout << "\n----------------------------------------\nПример 8\n----------------------------------------\n\n";
		cout << "Введите 3 различных числа" << endl;
		double M, N, L;
		cin >> M >> N >> L;
		if (L < M)
		{
			if (L < N)
			{
				L = (N + M) / 2;
				cout << L << endl;
			}
			else
			{
				N = (L + M) / 2;
				cout << N << endl;
			}
		}
		else
		{
			if (L < N)
			{
				M = (N + L) / 2;
				cout << M << endl;
			}
			else
			{
				if (N < M)
				{
					N = (L + M) / 2;
					cout << N << endl;
				}
				else
				{
					M = (N + L) / 2;
					cout << M << endl;
				}
			}
		}
		break;
	}
	case 9:
	{
		cout << "\n----------------------------------------\nПример 9\n----------------------------------------\n\n";
		cout << "Введите 4 различных числа" << endl;
		double A, B, C, D;
		cin >> A >> B >> C >> D;
		if (A > B && A > C && A > D)
		{
			cout << D / A << ", " << C / A << ", " << B / A << ", " << endl;
		}
		if (B > A && B > C && B > D)
		{
			cout << D / B << ", " << C / B << ", " << A / B << ", " << endl;
		}
		if (C > B && C > A && C > D)
		{
			cout << D / C << ", " << A / C << ", " << B / C << ", " << endl;
		}
		if (D > B && D > C && D > A)
		{
			cout << A / D << ", " << C / D << ", " << B / D << ", " << endl;
		}
		break;
	}
	case 10:
	{
		cout << "\n----------------------------------------\nПример 10\n----------------------------------------\n\n";
		int ram1;
		cout << "Введите 4 различных числа" << endl;
		cin >> A >> B >> C >> D;
		int max, min;
		max = 0;
		min = A;
		if (max < A)
		{
			max = A;
		}
		else if (min > A)
		{
			min = A;
		}
		if (max < B)
		{
			max = B;
		}
		else if (min > B)
		{
			min = B;
		}
		if (max < C)
		{
			max = C;
		}
		else if (min > C)
		{
			min = C;
		}
		int B1 = A + B + C - max - min;
		if (D > max)
		{
			A = D;
			B = max;
			C = B1;
			D = min;
		}
		else if (D > B1)
		{
			A = max;
			B = D;
			C = B1;
			D = min;
		}
		else if (D < B1 && D > min)
		{
			A = max;
			B = B1;
			C = D;
			D = min;
		}
		else if (D < min)
		{
			A = max;
			B = B1;
			C = min;
		}
		cout << "Порядок: " << A << ", " << B << ", " << C << ", " << D << endl;
		break;
	}
	case 11:
	{
		int bochki;
		cout << "Введите количество бочек:" << endl;
		cin >> bochki;
		if ((bochki == 10) || (bochki == 11) || (bochki == 12) || (bochki == 13) || (bochki == 14) || (bochki == 15) || (bochki == 16) || (bochki == 17) || (bochki == 18) || (bochki == 19) || (bochki % 100 == 10) || (bochki % 100 == 11) || (bochki % 100 == 12) || (bochki % 100 == 13) || (bochki % 100 == 14) || (bochki % 100 == 15) || (bochki % 100 == 16) || (bochki % 100 == 17) || (bochki % 100 == 18) || (bochki % 100 == 19))
		{
			cout << bochki << " bochek";
		}
		else if ((bochki % 10 == 2) || (bochki % 10 == 3) || (bochki % 10 == 4))
		{
			cout << bochki << " bochki";
		}
		else if (bochki % 10 == 1)
		{
			cout << bochki << " bochka";
		}
		else
		{
			cout << bochki << " bochek";
		}
		break;
	}
	case 12:
	{
		double V;
		int number;
		cout << "Введите размер диска в Мегабайтах:" << endl;
		cin >> V;
		cout << "Введите номер команды:" << endl;
		cin >> number;
		switch (number)
		{
			case 1:
			{
				V *= pow(2, 23);
				cout << "Размер состовляет" << V << "бит" << endl;
				break;
			}
			case 2:
			{
				V *= pow(2, 20);
				cout << "Размер состовляет" << V << "байт" << endl;
				break;
			}
			case 3:
			{
				V *= pow(2, 10);
				cout << "Размер состовляет" << V << "Килобайт" << endl;
				break;
			}
			case 4:
			{
				cout << "Размер состовляет" << V << "Мегабайт" << endl;
				break;
			}
			case 5:
			{
				V *= pow(2, -10);
				cout << "Размер состовляет" << V << "Гигабайт" << endl;
				break;
			}
			default:
			{
				cout << "Такой команды нет" << endl;
			}
		}
		break;
	}
	default:
	{
		cout << "Такой программы не существует" << endl;
	}
	}

	return 0;
}