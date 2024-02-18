#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int> Del(vector<int>A, int rasl)
{
	vector<int>New;
	for (int i = 0; i < A.size(); i++)
	{
		if (i == rasl-1)
		{
			continue;
		}
		New.push_back(A[i]);
	}
	return New;

}

template <typename T>
void Out(vector<T>Arr, int n)
{
	int zero = 0;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == 0)
		{
			zero++;
			continue;
		}
		if (i == n - 1)
		{
			cout << Arr[i] << endl;
			break;
		}
		cout << Arr[i] << "x^" << n - i - 1 << " ";
		if (Arr[i] > 0)
		{
			cout << "+ ";
		}
		if (Arr[i] < 0)
		{
			cout << "- ";
		}
	}
	if (zero == n)
	{
		cout << "0" << endl;
	}
}

template <typename T, typename T2>
T Calculate(vector<T> Arr, T2 x, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += Arr[i] * (int)pow(x, n-i-1);
	}
	return sum;
}

template <typename T>
void Arifm(vector<T>Arr, int n, vector<T>Arr1, int n1)
{
	cout << "Сумма:" << endl;
	if (n >= n1)
	{
		vector<T>Arrtemp = Arr;
		int ns = n - n1;
		for (int i = ns; i < n; i++)
		{
			Arrtemp[i] += Arr1[i - ns];
		}
		Out(Arrtemp, n);
	}
	else
	{
		vector<T>Arrtemp = Arr1;
		int ns = n1 - n;
		for (int i = ns; i < n1; i++)
		{
			Arrtemp[i] += Arr[i - ns];
		}
		Out(Arrtemp, n1);
	}
	cout << "Произведение:" << endl;
	int max = n + n1 - 1;
	vector<T>Arrs;
	Arrs.resize(max);
	for (int i = 0; i < max; i++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n1; j++)
			{
				if (k + j == i)
				{
					Arrs[i] += Arr[k] * Arr1[j];
				}
			}
		}
	}
	Out(Arrs, max);
	cout << "Частное:" << endl;
	if (n >= n1)
	{
		reverse(Arr.begin(), Arr.end());
		reverse(Arr1.begin(), Arr1.end());
		vector<T>Arrn;
		for (int i = n - 1; i >= 0; i--)
		{
			if (Arr.size() <= i)
			{
				continue;
			}
			double del = Arr[i] / Arr1[n1-1];
			Arrn.push_back(del);
			for (int j = n1 - 1; j >= 0; j--)
			{
				Arr[j + n - n1] -= del * Arr1[j];
			}
			int zero = 0;
			for (int k = n - 1; k >= 0; k--)
			{
				if (Arr[k] != 0)
				{
					break;
				}
				else
				{
					zero++;
					Arr.erase(Arr.begin() + k);
					if (zero == n1)
					{
						Arrn.push_back(0);
					}
				}
			}
			if (Arr.size() < Arr1.size())
			{
				break;
			}
			if(Arr.size() == Arr1.size())
			{
				del = Arr[n1 - 1] / Arr1[n1 - 1];
				for (int j = n1 - 1; j >= 0; j--)
				{
					Arr[j] -= del * Arr1[j];
				}
				Arrn.push_back(del);
				break;
			}
		}
		reverse(Arr.begin(), Arr.end());
		Out(Arrn, Arrn.size());
		cout << "\nОстаток:" << endl;
		Out(Arr, Arr.size());
	}
	else
	{
		cout << "0\nОстаток:" << endl;
		Out(Arr, n);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int number;
	cout << "Введите номер задания" << endl;
	cin >> number;
	switch (number)
	{
		case 1:
		{
			int n;
			cout << "Введите количество символов вектора:" << endl;
			cin >> n;
			int k;
			cout << "Введите индекс значения, которое будет удалено:" << endl;
			cin >> k;
			vector<int>Arr;
			Arr.resize(n);
			cout << "Введите элементы вектора:" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> Arr[i];
			}
			Arr = Del(Arr, k);
			cout << "Вектор без элемента под индексом k:" << endl;
			for (int i = 0; i < n - 1; i++)
			{
				cout << Arr[i] << endl;
			}
			break;
		}
		case 2:
		{
			int n;
			cout << "Введите длину вектора:" << endl;
			cin >> n;
			vector<int>Arr;
			Arr.resize(n);
			cout << "Введите коэффиценты многочлена:" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> Arr[i];
			}
			cout << "Многочлен:" << endl;
			Out(Arr, n);
			int make;
			cout << "Введите желаемую функцию:\n1. Вычислить значение многочлена\n2. Сумма, произведение, неполное частное, остаток от частного многочленов" << endl;
			cin >> make;
			switch (make)
			{
				case 1:
				{
					int x;
					cout << "Введите x:" << endl;
					cin >> x;
					cout << Calculate(Arr, x, n);
					break;
				}
				case 2:
				{
					int n1;
					cout << "Введите длину вектора:" << endl;
					cin >> n1;
					vector<int>Arr1;
					Arr1.resize(n1);
					cout << "Введите коэффиценты многочлена:" << endl;
					for (int i = 0; i < n1; i++)
					{
						cin >> Arr1[i];
					}
					cout << "Многочлен:" << endl;
					Out(Arr1, n1);
					Arifm(Arr, n, Arr1, n1);
					break;
				}
			}
			break;
		}
		default:
		{
			cout << "" << endl;
		}
	}


}
