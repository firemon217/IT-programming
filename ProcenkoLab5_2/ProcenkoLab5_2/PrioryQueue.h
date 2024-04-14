#pragma once
#include"string"

using namespace std;

template<typename Data> //Шаблонный класс очереди с приоритетом
class PrioryQueue
{
	class Node //Элемент очереди
	{
		public:
			Data data; //Значение элемента
			Node* prev; //Указатель на предыдущий элемент
			Node* next; //Указатель на следующий элемент
			Node(Data dat = 0) //Конструктор
			{
				data = dat;
				next = prev = 0;
			}
	};
	Node* pbegin; //Указатель на первый элемент очереди
	Node* pend; //Указатель на последний элемент очереди
	public:
		void Add(Data dat) //Добавляет элемент в очередь
		{
			Node* pelem = new Node(dat); //Новый элемент
			if (pbegin == pend == 0) //Если элементов еще нет
			{
				pbegin = pend = pelem;
			}
			else //Если элементы уже есть
			{
				pelem->prev = pend; 
				pend->next = pelem;
				pend = pelem;
			}
		};
		PrioryQueue() { pbegin = 0; pend = 0; }; //Конструктор
		void Remove() //Удаление элемента из очереди (Удаляет самый большой элемент)
		{
			Node* pelem = pbegin; 
			int maxim = -1000000000; //Максимальное значение
			while (pelem) //Перебираем элементы
			{
				if (maxim < pelem->data) //Ищим максимальный элемент очереди
				{
					maxim = pelem->data;
				}
				pelem = pelem->next;
			}
			pelem = pbegin;
			while (pelem) //Перебираем элементы
			{
				if (pelem->data == maxim) //Если находим элемент/ы - удаляем его
				{
					(pelem->prev)->next = pelem->next;
					(pelem->next)->prev = pelem->prev;
				}
				pelem = pelem->next;
			}
			delete pelem;
		};
		Node* Find(Data key) //Находим элемент по значению
		{
			Node* pelem = pbegin;
			while (pelem) //Перебираем элементы
			{
				if (pelem->data == key) //Если находим, выходим из перебора
				{
					break;
				}
				pelem = pelem->next;
			}
			return pelem; //Возвращаем элемент
		};
		void Print() //Отрисовываем элемент
		{
			Node* pelem = pbegin;
			cout << "Queue: " << endl;
			while (pelem) //Перебираем элементы и выводим их
			{
				cout << pelem->data << ' ';
				pelem=pelem->next;
			}
			cout << endl;
		};
};