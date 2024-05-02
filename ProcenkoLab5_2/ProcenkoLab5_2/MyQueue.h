#pragma once
#include<iostream>
#include<List>

using namespace std;

template <typename T>
class MyQueue
{
	list<T> queue; //Поле-контейнер по условию задания
	public:
		void Menu(); //Меню
		void Push(T elem); //Добавить элемент
		void Del(); //Удалить элемент
		void Show(); //Вывести элементы
};