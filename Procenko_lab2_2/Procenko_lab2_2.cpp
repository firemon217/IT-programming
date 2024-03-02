#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Enrollee //Класс абитуриента
{
public:

	Enrollee(string surname, string name, string patronymic, string sex, string nationality, string adress, string berthday, int sumExamMarks, int passMark) //Конструктор, записывающий все данные при создании экземпляра
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->sex = sex;
		this->nationality = nationality;
		this->adress = adress;
		this->berthday = berthday;
		this->sumExamMarks = sumExamMarks;
		this->passMark = passMark;
		cout << "Карточка абитуриента создана:" << endl;
	}
	string GetInformation() const //Получаем данные об абитуриенте
	{ 
		string iform = this->surname + " " + this->name + " " + this->patronymic + " " + this->sex + " " + this->nationality + " " + this->adress + " " + this->berthday + " " + to_string(this->sumExamMarks) + " " + to_string(this->passMark) + "\n";
		return iform; 
	}
	void SetInformation(string surname, string name, string patronymic, string sex, string nationality, string adress, string berthday, int sumExamMarks, int passMark) //Устанавливаем данные абитуриента
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->sex = sex;
		this->nationality = nationality;
		this->adress = adress;
		this->berthday = berthday;
		this->sumExamMarks = sumExamMarks;
		this->passMark = passMark;
	}
	string surname, name, patronymic, sex, nationality, adress, berthday;
	int sumExamMarks, passMark; //Скорытые данные абитуриента
};

ostream& operator << (ostream& os, const Enrollee enrollee) //Переопределение оператора << для Enrollee
{
	return os << enrollee.surname << " " << enrollee.name << " " << enrollee.patronymic << " " << enrollee.sex << " " << enrollee.nationality << " " << enrollee.adress << " " << enrollee.berthday << " " << enrollee.sumExamMarks << " " << enrollee.passMark << " " << "\n";
}

istream& operator >> (istream& in, Enrollee& enrollee)  //Переопределение оператора >> для Enrollee
{
	string surname, name, patronymic, sex, nationality, adress, berthday;
	int sumExamMarks, passMark;
	in >> surname >> name >> patronymic >> sex >> nationality >> adress >> berthday >> sumExamMarks >> passMark;
	enrollee.SetInformation(surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks, passMark);
	return in;
}


struct Book //Класс книги, в котором указаны имя автора, название книги, тираж, цена и год написания
{
	string nameAuthor;
	string nameBook;
	int circulation;
	double price;
	int year;
	void setBook(string nameAuthor, string nameBook, int circulation, double price, int year) //Установка данных
	{
		this->nameAuthor = nameAuthor;
		this->nameBook = nameBook;
		this->circulation = circulation;
		this->price = price;
		this->year = year;
	}
};

ostream& operator << (ostream& os, const Book book) //Переопределение оператора << для Book
{
	return os << book.nameAuthor << " " << book.nameBook << " " << book.circulation << " " << book.price << " " << book.year << "\n";
}

istream& operator >> (istream& in, Book& book)  //Переопределение оператора >> для Book
{
	string nameAuthor, nameBook;
	int circulation, year;
	double price;
	in >> nameAuthor >> nameBook >> circulation >> price >> year;
	book.setBook(nameAuthor, nameBook, circulation, price, year);
	return in;
}

struct Internet //Интернет пользователи, имена, цена за интернет, оплаченно месяцев, доп месяцы
{
	string name = " ";
	double priceInternet = 0.;
	int month = 0;
	int extraMonth = 0;
	bool isDiscount = false;
	void setInternet(string name, double priceInternet, int month, int extraMonth, bool isDiscount) //Установка данных
	{
		this->name = name;
		this->priceInternet = priceInternet;
		this->month = month;
		this->extraMonth = extraMonth;
		this->isDiscount = isDiscount;
	}
};

ostream& operator << (ostream& os, const Internet internet) //Переопределение оператора << для Internet
{
	return os << internet.name << " " << internet.priceInternet << " " << internet.month << " " << internet.extraMonth << " " << internet.isDiscount << endl;
}

istream& operator >> (istream& in, Internet& internet)  //Переопределение оператора >> для Book
{
	string name;
	double priceInternet;
	int month, extraMonth;
	bool isDiscount;
	in >> name >> priceInternet >> month >> extraMonth >> isDiscount;
	internet.setInternet(name, priceInternet, month, extraMonth, isDiscount);
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
					fstream txt("a.txt", ios::in); //Открываем Файл в режиме чтения
					fstream txt1("a1.txt", ios::out); //Открываем Файл в режиме записи
					char n;
					while (txt >> n) 
					{
						txt1 << n; //Переносим фсе из первого файла во второй
					}
					txt.close();
					txt1.close();
					txt.open("a.txt", ios::out); //Открываем в режиме записи
					txt1.open("a1.txt", ios::in); //Открываем в режиме чтения
					while (txt1 >> n)
					{
						if (!((((int)n >= 65) && ((int)n <= 90)) || (((int)n >= 97) && ((int)n <= 122))))
						{
							txt << n; //Возвращаем в первый файл элементы, подходящие по условию
						}
					}
					txt.close();
					txt.open("a.txt", ios::in); //Открываем Файл в режиме чтения
					ReadTxt<char>(txt); //Выводим содержимое
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
					fstream txt("a.txt", ios::out); //Открываем файл для записи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<int>(txt); //Вызов функции для записи в файл
					}
					txt.close();
				}
				case 2:
				{
					fstream txt("a.txt", ios::in); //Открываем файл для чтения
					int inum = 1; //Для вычисления порядка
					int count = 0; //Количество подходящих чисел
					int n;
					while (txt >> n)
					{
						if (inum % 3 == 0 && n < 0) //Порядок = 3 и число меньше 0
						{
							count++; //Считаем
						}
						inum++; //Продвигаемся по порядку
					}
					cout << "Количество удовлетворяющих условию чисел: " << count << endl; //Выводим количество чисел
					break;
				}
				default:
				{
					cout << "Такого действия нет, извините" << endl;
				}
			}
			break;
		}
		case 5:
		{
			cout << "Работа с картотекой абитуриентов:" << endl;
			while (true)
			{
				cout << "Выбирете действие:\n1. Создать новую запись абитуриента\n2. Вывести все карточки абитуриентов\n3. Отчистить базу абитуриентов\n4. Выйти" << endl;
				int choice; //Выбор действия над картотекой абитуриентов
				cin >> choice;
				switch (choice)
				{
					case 1: //Создает новую запись в файл
					{
						string surname, name, patronymic, sex, nationality, adress, berthday;
						int sumExamMarks, passMark; //Записываем все данные абитуриента
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
						cout << "Введите ваш проходной балл:" << endl;
						cin >> passMark;
						Enrollee enrollee(surname, name, patronymic, sex, nationality, adress, berthday, sumExamMarks, passMark); //Создаем экземпдяр класса с данными абитуриента
						fstream txt("Enrollee.txt", ios::app || ios::binary); //Открываем файл для дополнения
						txt << enrollee; //Дописываем ифнормацию о новом абитуриенте
						txt.close();
						break;
					}
					case 2: //Считывает весь файл
					{
						fstream txt("Enrollee.txt", ios::in || ios::binary); //Открываем для чтения
						vector<Enrollee> listEnrollee; //Создаем вектор для хранения абитуриентов
						Enrollee enr("f", "f", "f", "f", "f", "f", "f", 0, 0);
						while (txt >> enr) //Записываем по одному абитуриенту в экземпляр
						{
							listEnrollee.push_back(enr); //Записываем данные в базу
						}
						for (const Enrollee& en : listEnrollee)
						{
							if (en.passMark >= 4)
							{
								cout << en; //Выводим данные из базы абитуриентов
							}
						}
						break;
					}
					case 3: //Отчищает файл
					{
						fstream txt("Enrollee.txt", ios::out); //Открываем для перезаписи
						txt.close();
						cout << "База отчищена:" << endl;
						break;
					}
					case 4: //Прекращает работу кода
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
			break;
		}
		case 6:
		{
			cout << "Перезаписать файл или использовать исходный?\n 1 - перезаписать 2 - исходный" << endl;
			int zap;
			cin >> zap; //Выбор действия, перезапись или использование исходного файла
			switch (zap)
			{
				case 1:
				{
					fstream txt("f.txt", ios::out); //Открываем файл в режиме перезаписи
					cout << "Идет запись в файл:" << endl;
					if (txt.is_open()) //Проверка на открытие файла
					{
						WriteTxt<char>(txt); //Вызов функции для записи в файл
					}
					txt.close(); //Закрываем перезапись файла
				}
				case 2:
				{
					fstream txt("f.txt", ios::in); //Открываем в режиме чтения
					fstream txtTemp("h.txt", ios::out); //Открываем файл в режиме записи
					char temp;
					while (txt >> temp) //Запись во временный файл
					{
						txtTemp << temp << endl;
					}
					txt.close();
					txtTemp.close();
					txtTemp.open("h.txt", ios::in); //Открываем временный файл в режиме чтения
					fstream txt1("f1.txt", ios::out); //Открываем файл в режиме перезаписи
					while (txtTemp >> temp) //Переписываем из временного файла в нужный
					{
						txt1 << temp << endl;
					}
					txt1.close();
					txtTemp.close(); //Закрываем файлы
					txt1.open("f1.txt", ios::in); //Открываем в режиме чтения
					ReadTxt<char>(txt1); //Считываем все данные
					txt1.close();
					break;
				}
			}
			break;
		}
		case 7:
		{
			fstream txt("matrix.txt", ios::in); //Открываем файл с матрицами в режиме чтения
			string co;  //Первая строка для считывания размера матрицы
			int count; //Размер матрицы
			int iter; //Итератор для записи в вектор матрицы
			txt.seekg(0, ios::end); //Перемещаем курсор файла в конец
			size_t point = 0; //Курсор файла
			txt.seekg(0, ios::beg); //Возвращаем курсор в начало файла
			while (getline(txt, co)) //Считываем первый строки матриц
			{
				txt.seekg(point, ios::beg); //Перемещаем курсор на начало матрицы, которое указывается в конце цикла
				vector<vector<int>> mat; //Вектор матрицы
				iter = 0; 
				count = co.size() / 2 + 1; //Устанавливаем размер матрицы
				mat.resize(count); //Записываем размер вектора
				int n;
				int counter = 1; //Счетчик
				while (txt >> n) //Считываем эдементы
				{
					if (iter == count) //Если дошли до конца матрицы
					{
						break;
					}
					mat[iter].push_back(n); //Записываем элементы в нужные строки
					if (counter == count) //Переход на нужную строку по счетчику
					{
						counter = 1;
						iter++;
						continue;
					}
					counter++;
				}
				vector<vector<int>> matTransp; //Вектор транспанированной матрицы
				matTransp.resize(count); //Устанавливаем тот же размер
				for (int i = 0; i < count; i++) //Транспанирование сходной матрицы
				{
					for (int j = 0; j < count; j++)
					{
						matTransp[j].push_back(mat[i][j]);
					}
				}
				int usl = 0; //Равенство матриц
				for (int i = 0; i < count; i++) //Проверка на симметричность
				{
					for (int j = 0; j < count; j++)
					{
						if (matTransp[i][j] == mat[i][j])
						{
							usl += 1;
						}
						else
						{
							break;
						}
					}
				}
				if (usl == count * count) //Если матрицы симметричны
				{
					fstream txt1("matrix1.txt", ios::app);//Открываем файл в режиме дописывания
					for (int i = 0; i < count; i++) //Записываем транспанированную матрицу, равную исходной
					{
						for (int j = 0; j < count; j++)
						{
							txt1 << matTransp[i][j] << " ";
						}
						txt1 << endl;
					}
					txt1.close();
				}
				else
				{
					fstream txt1("matrix2.txt", ios::app); //Открываем файл для дозаписи
					for (int i = 0; i < count; i++) //Записываем транспанированную матрицу, не равную исходной
					{
						for (int j = 0; j < count; j++)
						{
							txt1 << matTransp[i][j] << " ";
						}
						txt1 << endl;
					}
					txt1.close();
				}
				point = txt.tellg(); //Устанавливаем позицию курсора на начало следующей матрицы
				point--;
			}
			txt.close();
			txt.open("matrix.txt", ios::in); //Далее мы просто выводим содержимое файлов
			fstream txt1("matrix1.txt", ios::in);
			fstream txt2("matrix2.txt", ios::in);
			cout << "Содержимое первого файла:\n" << endl;
			ReadTxt<int>(txt);
			cout << "Содержимое второго файла:\n" << endl;
			ReadTxt<int>(txt1);
			cout << "Содержимое третьего файла:\n" << endl;
			ReadTxt<int>(txt2);
			txt1.close();
			txt2.close();
			txt1.open("matrix1.txt", ios::out);
			txt2.open("matrix2.txt", ios::out);
			txt1.close();
			txt2.close();
			break;
		}
		case 8:
		{
			fstream txt("Book.txt", ios::app | ios::binary); //Открываем файл для дозаписи в бинарном режиме
			string nameAuthor; //Значения книги
			string nameBook;
			int circulation;
			double price;
			int year;
			cout << "Введите имя Автора:" << endl; //Ввод значений
			cin >> nameAuthor;
			cout << "Введите название Книги:" << endl;
			cin >> nameBook;
			cout << "Введите тираж:" << endl;
			cin >> circulation;
			cout << "Введите цену:" << endl;
			cin >> price;
			cout << "Введите год написание:" << endl;
			cin >> year;
			vector<Book> listBooks; //Список всех книг
			Book book; //Экземпляр книги
			book.setBook(nameAuthor, nameBook, circulation, price, year); //Устанавливаем значения в экземпляр
			txt << book; //Записываем книгу в файл
			txt.close();
			txt.open("Book.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			while (txt >> book) //Записываем значения из файла
			{
				listBooks.push_back(book); //Переносим их в вектор
			}
			int iter; //Итератор
			for (int i = 0; i < (int)listBooks.size(); i++)
			{
				iter = 0;
				for (char f : listBooks[i].nameBook)
				{
					if (f == 'K' || f == 'k' || f == 'i' || f == 'l') //Проверяем на совпадения
					{
						iter++;
						if (iter == 4)
						{
							book = listBooks[i]; //Выводим совпавшие книги
							cout << book;
							break;
						}
						continue;
					}
				}
			}
			break;
		}
		case 9:
		{
			fstream txt("Memo.txt", ios::app | ios::binary); //Открываем в режиме бинарной дозаписи
			double num;
			cin >> num;
			txt << num << endl; //Заносим число в файл
			txt.close();
			txt.open("Memo.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			ReadTxt<double>(txt); //Считываем все элементы файла
			txt.close();
			txt.open("Memo.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			vector<double> listNums; //Список всех элементов
			while (txt >> num)
			{
				num *= 1.5;
				listNums.push_back(num); //Записываем из текста все элементы в вектор, умноженныена 1.5
			}
			txt.close();
			txt.open("Memo.txt", ios::out | ios::binary); //Открывае в режиме бинарной перезаписи
			for (double i : listNums) //Переносим все элементы обратно в файл
			{
				txt << i << endl;
			}
			txt.close();
			txt.open("Memo.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			ReadTxt<double>(txt); //Выводим обновленные элементы
			break;
		}
		case 10:
		{
			fstream txt("Internet.txt", ios::app | ios::binary); //Открываем в режиме бинарной дозаписи
			Internet internet; //Экземпляр пользователей интернет услуги
			string name; //Значения услуги
			double priceInternet;
			int month, extraMonth;
			cout << "Введите имя клиента интернет сети:" << endl;
			cin >> name;
			cout << "Введите стоимость оплаты услуг интернет:" << endl;
			cin >> priceInternet;
			cout << "Введите количество месяцев оплаты за услуги интернет сети:" << endl;
			cin >> month;
			extraMonth = month - 1;
			internet.setInternet(name, priceInternet, month, extraMonth, false); //Устанавливаем эти значения в экземпляр
			txt << internet; //Записываем в файл
			txt.close();
			txt.open("Internet.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			vector<Internet> interList; //Вектор всех пользователей услуг
			while (txt >> internet) //Из файла выписываем всех пользователей 
			{
				interList.push_back(internet);
			}
			txt.close();
			txt.open("Internet.txt", ios::out | ios::binary); //Открываем в режиме бинарной перезаписи
			for (Internet i : interList) //Проверяем всех пльзователей
			{
				if (i.extraMonth >= 3 && !i.isDiscount) //Если доп месяцев больше 3 и скидки еще не было
				{
					i.priceInternet *= 0.93; //Изменяем цену со скидкой
					i.isDiscount = true; //Записываем, что скидка уже есть
				}
				txt << i;
			}
			txt.close();
			txt.open("Internet.txt", ios::in | ios::binary); //Открываем в режиме бинарного чтения
			ReadTxt<Internet>(txt); //Считываем данные файла
			break;
		}
		default:
		{
			return 1;
		}
	}
}
