#include <iostream>
#include "PrioryQueue.h"
#include "PrioryQueue.cpp"
#include "MyQueue.h"
#include "MyQueue.cpp"
#include"string"

int main()
{
    cout << "Enter number:" << endl;
    int number;
    cin >> number;
    switch (number)
    {
        case 1:
        {
            PrioryQueue<int> queueP;
            queueP.Add(1);
            queueP.Add(2);
            queueP.Add(3);
            queueP.Add(5);
            queueP.Remove();
            queueP.Add(4);
            queueP.Print();
            break;
        }
        case 2:
        {
            MyQueue<int> queue;
            queue.Menu();
            break;
        }
        default:
        {
            cout << "None";
        }
    }
}
