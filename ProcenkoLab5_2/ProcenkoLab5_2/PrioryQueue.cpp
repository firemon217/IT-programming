//#include"PrioryQueue.h"
//#include<iostream>
//
//using namespace std;
//
//template<typename Data>
//void PrioryQueue<Data>::Add(Data dat)
//{
//	Node* pelem = new Node(dat);
//	if (pbegin == 0)
//	{
//		pbegin = pend = pelem;
//	}
//	else
//	{
//		pelem->prev = pend;
//		pend->next = pelem;
//		pend = pelem;
//	}
//}
//
//template<typename Data>
//PrioryQueue<Data>::Node* PrioryQueue<Data>::Find(Data key)
//{
//	Node* pelem = pbegin;
//	while (pelem)
//	{
//		if (pelem->data == key)
//		{
//			break;
//		}
//		else
//		{
//			pelem = pelem->next;
//		}
//	}
//	return pelem;
//}
//
//template<typename Data>
//void PrioryQueue<Data>::Remove()
//{
//	Node* pelem = pbegin;
//	int maxim = -1000000000;
//	while (pelem)
//	{
//		if (maxim > pelem->data)
//		{
//			maxim = pelem->data;
//		}
//		pelem->next;
//	}
//	pelem = pbegin;
//	while (pelem)
//	{
//		if (pelem->data - maxim)
//		{
//			(pelem->prev)->next = pelem->next;
//			(pelem->next)->prev = pelem->prev;
//		}
//	}
//	delete pelem;
//}
//
//template<typename Data>
//void PrioryQueue<Data>::Print()
//{
//	Node* pelem = pbegin;
//	cout << "Queue: " << endl;
//	while (pelem)
//	{
//		cout << pelem->data << ' ';
//		pelem->next;
//	}
//}