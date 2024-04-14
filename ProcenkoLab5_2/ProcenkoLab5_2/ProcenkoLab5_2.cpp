#include <iostream>
#include "PrioryQueue.h"
#include"string"

int main()
{
    PrioryQueue<int> queue;
    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);
    queue.Add(4);
    queue.Add(4);
    queue.Add(4);
    queue.Add(4);
    queue.Add(3);
    queue.Print();
    queue.Remove();
    queue.Print();
}
