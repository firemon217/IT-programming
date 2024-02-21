#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Enrollee
{
public:

	Enrollee(string surname, string name, string patronymic, string sex, string nationality, string adress, string berthday, string sumExamMarks)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->sex = sex;
		this->nationality = nationality;
		this->adress = adress;
		this->berthday = berthday;
		this->sumExamMarks = sumExamMarks;
		cout << "Карточка абитуриента создана:" << endl;
	}

	string GetInformation() const 
	{ 
		string iform = this->surname + " " + this->name + " " + this->patronymic + " " + this->sex + " " + this->nationality + " " + this->adress + " " + this->berthday + " " + this->sumExamMarks + "\n";
		return iform; 
	}
	void SetInformation(string surname, string name, string patronymic, string sex, string nationality, string adress, string berthday, string sumExamMarks)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->sex = sex;
		this->nationality = nationality;
		this->adress = adress;
		this->berthday = berthday;
		this->sumExamMarks = sumExamMarks;
	}

	~Enrollee()
	{

	}

private:
	string surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks;
};

ostream& operator << (ostream& os, const Enrollee enrollee)
{
	return os << enrollee.GetInformation();
}

istream& operator >> (istream& in, Enrollee& enrollee)
{
	string surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks;
	in >> surname >> name >> patronymic >> sex >> nationality >> adress >> berthday >> sumExamMarks;
	enrollee.SetInformation(surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks);
	return in;
}





template<typename T>
fstream& WriteTxt(fstream& txt) //Шаблонная функция для записи элементов в файл
{
	T n;
	cout << "0 - выход из записи" << endl;
	while (cin >> n)
	{
		if (n == 0) //0 - выходит из записи
		{
			break;
		}
		txt << n << endl;
	}
	return txt;
}

template<> fstream& WriteTxt<char>(fstream& txt) //Шаблонная функция для записи элементов в файл
{
	char n;
	cout << "0 - выход из записи" << endl;
	while (cin >> n)
	{
		if (n == '0') //0 - выходит из записи
		{
			break;
		}
		txt << n << endl;
	}
	return txt;
}

template<typename T>
void ReadTxt(fstream& txt) //Шаблонная функция для записи элементов в файл
{
	T n;
	while (txt >> n)
	{
		cout << n << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите номер задания:" << endl;
	int number; // Выбираем номер задания
	cin >> number;
	switch (number) //Задания пронумерованы от 1 до 10, если введена другая задача - произойдет выход
	{
		case 1: //Дан файл вещественных чисел a.txt Найти количество элементов равных 5 и сумму положительных элементов.
		{
			cout << "Перезаписать файл или использовать исходный?\n 1 - перезаписать 2 - исходный" << endl;
			int zap;
			cin >> zap; //Выбор действия, перезапись или использование исходного файла
			switch (zap)
			{
				case 1:
				{
					fstream txt("a.txt", ios::out); //Открываем файл в режиме перезаписи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<double>(txt); //Вызов функции для записи в файл
					}
					txt.close(); //Закрываем перезапись файла
				}
				case 2:
				{
					fstream txt("a.txt", ios::in); //Открываем в режиме чтения
					vector<double> num; //Создаем вектор вещественных чисел, в который запишем все данные из файла
					double n;
					while (txt >> n)
					{
						num.push_back(n); //Записываем в вектор данные из файла
					}
					double sum = 0; //Сумма положительных чисел
					int count = 0; //Количество чисел, больших 5
					for (double n : num) //Перебераем элементы вектора
					{
						if (n == 5) //Если элемент = 5
						{
							count++;
						}
						if (n >= 0) //Если элемент положительный
						{
							sum += n;
						}
					}
					cout << "Сумма положительных элементов в тексте: " << sum << ", количество 5 в тексте: " << count << endl;
					txt.close(); //Закрываем файл
					break;
				}
				default:
				{
					cout << "Такого действия нет, извините" << endl;
				}
			}
			break;
		}
		case 2:
		{
			cout << "Перезаписать файл или использовать исходный?\n 1 - перезаписать 2 - исходный" << endl;
			int zap;
			cin >> zap; //Выбор действия, перезапись или использование исходного файла
			switch (zap)
			{
				case 1:
				{
					fstream txt("a.txt", ios::out); //Открываем файл в режиме перезаписи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<double>(txt); //Вызов функции для записи в файл
					}
					txt.close(); //Закрываем перезапись файла
				}
				case 2:
				{
					fstream txt("a.txt", ios::in); //Открываем в режиме чтения
					fstream txt1("a1.txt", ios::out); //Открываем в режиме записи
					double n;
					while (txt >> n) //Переписываем отрицательные элементы*2 в другой файл
					{
						if (n < 0)
						{
							txt1 << n*2;
						}
					}
					txt.close();
					txt1.close();
					txt1.open("a1.txt", ios::in);
					txt1.seekg(0); //Возвращаем указатель в начало
					ReadTxt<double>(txt1); //Считываем документ
					txt1.close();
					break;
				}
				default:
				{
					cout << "Такого действия нет, извините" << endl;
				}
			}
			break;
		}
		case 3:
		{
			cout << "Перезаписать файл или использовать исходный?\n 1 - перезаписать 2 - исходный" << endl;
			int zap;
			cin >> zap; //Выбор действия, перезапись или использование исходного файла
			switch (zap)
			{
				case 1:
				{
					fstream txt("a.txt", ios::out); //Открываем файл в чтения и записи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<char>(txt); //Вызов функции для записи в файл
					}
					txt.close();
				}
				case 2:
				{
					fstream txt("a.txt", ios::in);
					fstream txt1("a1.txt", ios::out);
					char n;
					while (txt >> n)
					{
						txt1 << n;
					}
					txt.close();
					txt1.close();
					txt.open("a.txt", ios::out);
					txt1.open("a1.txt", ios::in);
					while (txt1 >> n)
					{
						if (!((((int)n >= 65) && ((int)n <= 90)) || (((int)n >= 97) && ((int)n <= 122))))
						{
							txt << n;
						}
					}
					txt.close();
					txt.open("a.txt", ios::in);
					ReadTxt<char>(txt);
					txt.close();
					break;
				}
				default:
				{
					cout << "Такого действия нет, извините" << endl;
				}
			}
			break;
		}
		case 4:
		{
			cout << "Перезаписать файл или использовать исходный?\n 1 - перезаписать 2 - исходный" << endl;
			int zap;
			cin >> zap; //Выбор действия, перезапись или использование исходного файла
			switch (zap)
			{
				case 1:
				{
					fstream txt("a.txt", ios::out); //Открываем файл в чтения и записи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<int>(txt); //Вызов функции для записи в файл
					}
					txt.close();
				}
				case 2:
				{
					fstream txt("a.txt", ios::in);
					int inum = 0;
					int count = 0;
					int n;
					while (txt >> n)
					{
						if (inum % 3 == 0 && n < 0)
						{
							count++;
						}
						inum++;
					}
					cout << count << endl;
					break;
				}
			}
		}
		case 5:
		{
			cout << "Работа с картотекой студентов:" << endl;
			while (true)
			{
				cout << "Выбирете действие:\n1. Создать новую запись студента\n2. Вывести все карточки студентов\n3. Отчистить базу студентов\n4. Выйти" << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
					case 1:
					{
						string surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks;
						cout << "Вместо пробела используйте '_'" << endl;
						cout << "Введите вашу Фамилию:" << endl;
						cin >> surname;
						cout << "Введите ваше Имя:" << endl;
						cin >> name;
						cout << "Введите ваше Отчество:" << endl;
						cin >> patronymic;
						cout << "Введите ваш Пол:" << endl;
						cin >> sex;
						cout << "Введите вашу Национальность:" << endl;
						cin >> nationality;
						cout << "Введите ваш Адрес:" << endl;
						cin >> adress;
						cout << "Введите вашу Дату рождения:" << endl;
						cin >> berthday;
						cout << "Введите ваш Балл по экзаменам (3 предмета в сумме):" << endl;
						cin >> sumExamMarks;
						Enrollee enrollee(surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks);
						cout << enrollee;
						fstream txt("Enrollee.txt", ios::app);
						txt << enrollee;
						txt.close();
						break;
					}
					case 2:
					{
						fstream txt("Enrollee.txt", ios::in);
						vector<Enrollee> listEnrollee;
						Enrollee enr("f", "f", "f", "f", "f", "f", "f", "f");
						while (txt >> enr)
						{
							listEnrollee.push_back(enr);
						}
						for (const Enrollee& en : listEnrollee)
						{
							cout << en;
						}
						break;
					}
					case 3:
					{
						fstream txt("Enrollee.txt", ios::out);
						txt.close();
						cout << "База отчищена:" << endl;
						break;
					}
					case 4:
					{
						cout << "Хорошего дня!!" << endl;
						return 1; 
					}
					default:
					{
						cout << "Такого действия нет, досвидания!" << endl;
						return 1;
					}
				}
			}
		}
	}
}
