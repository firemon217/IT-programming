#include"MyQueue.h"

template<typename T>
void MyQueue<T>::Menu() //Допольнителное удобство в тестировании в виде меню
{
	bool go = true;
	while (go)
	{
		cout << "1. Push \n2. Del \n3. Show" << endl; //Выбор метода
		int number;
		cin >> number;
		switch (number)
		{ 
			case 1: //Добавляем Элемент
			{
				T elem;
				try //Проверяем на нужный тип
				{
					cout << "Enter element" << endl;
					cin >> elem;
				}
				catch (T i)
				{
					cout << "Error" << endl;
					go = false;
					break;
				}
				Push(elem);
				break;
			}
			case 2: //Удаляем элемент
			{
				cout << "Element was deleted" << endl;
				Del();
				break;
			}
			case 3: //Выводимм элементы
			{
				cout << "Your elements" << endl;
				Show();
				break;
			}
			default:
			{
				cout << "Nothing" << endl;
				go = false;
			}
		}
	}
}

template<typename T>
void MyQueue<T>::Push(T elem) //Реализация Push
{
	queue.push_back(elem); //Добавляем в наш контейнер-поле элемент
}

template<typename T>
void MyQueue<T>::Del() //Реализация Del
{
	queue.pop_front(); //Удаляем элемент из поля
}

template<typename T>
void MyQueue<T>::Show() //Реализация Show
{
	for (T elem : queue) //Перебераем элементы поля
	{
		cout << elem << " "; //Вывод
	}
	cout << endl;
}