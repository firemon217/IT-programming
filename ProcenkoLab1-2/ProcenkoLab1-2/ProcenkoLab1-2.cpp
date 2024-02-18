#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <math.h>

using namespace std;

template<typename T>
void ShowQueue(queue<T> queue)
{
    cout << "Все элементы очереди: " << endl;
    int size = queue.size();
    for (int i = 0; i < size; i++)
    {
        cout << queue.front() << endl;
        queue.pop();
    }
}

template<typename T>
queue<T> FillQueue(queue<T> queue)
{
    cout << "Введите элементы очереди, выход из заполения '0': " << endl;
    T n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        queue.push(n);
    }
    return queue;
}

template<typename T>
void ShowStack(stack<T> stack)
{
    cout << "Все элементы стека: " << endl;
    int size = stack.size();
    for (int i = 0; i < size; i++)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}

template<typename T>
stack<T> FillStack(stack<T> stack)
{
    cout << "Введите элементы стека, выход из заполения '0': " << endl;
    T n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        stack.push(n);
    }
    return stack;
}

stack<string> FillStack(stack<string> stack)
{
    cout << "Введите элементы стека, выход из заполения '0': " << endl;
    string n;
    cin.ignore();
    while (true)
    {
        getline(cin, n);
        if (n == "0")
        {
            break;
        }
        stack.push(n);
    }
    return stack;
}

template<typename T>
void ShowForList(forward_list<T> list)
{
    cout << "Все элементы списка: " << endl;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        cout << *i << endl;
    }
}

template<typename T>
forward_list<T>  FillForList(forward_list<T> list)
{
    cout << "Введите элементы списка, выход из заполения '0': " << endl;
    T n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        list.push_front(n);
    }
    forward_list<T> newList;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        newList.push_front(*i);
    }
    return newList;
}

forward_list<char>  FillForList(forward_list<char> list)
{
    cout << "Введите элементы списка, выход из заполения '0': " << endl;
    char n;
    while (cin >> n)
    {
        if (n == '0')
        {
            break;
        }
        list.push_front(n);
    }
    forward_list<char> newList;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        newList.push_front(*i);
    }
    return newList;
}

template<typename T>
void ShowList(list<T> list)
{
    cout << "Все элементы списка: " << endl;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        cout << *i << endl;
    }
}

template<typename T>
list<T>  FillList(list<T> list)
{
    cout << "Введите элементы списка, выход из заполения '0': " << endl;
    T n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        list.push_back(n);
    }
    return list;
}

forward_list <double> Enqueue(forward_list <double> queue, int* size, double n)
{
    queue.resize(*size + 1);
    *size += 1;
    int j = *size - 2;
    auto places = queue.begin();
    for (int i = 0; i < j; i++)
    {
        places++;
    }
    queue.emplace_after(places, n);
    return queue;
}

forward_list <double> Dequeue(forward_list <double> queue, int* size)
{
    queue.pop_front();
    *size -= 1;
    return queue;
}

void ShowListQueue(forward_list <double> queue)
{
    cout << "Все элементы очереди: " << endl;
    while (!queue.empty())
    {
        cout << queue.front() << endl;
        queue.pop_front();
    }
}

forward_list <string> Push(forward_list <string> stack, int*size, string n)
{
    stack.resize(*size + 1);
    *size += 1;
    int j = *size - 2;
    auto places = stack.begin();
    for (int i = 0; i < j; i++)
    {
        places++;
    }
    stack.emplace_after(places, n);
    return stack;
}

forward_list <string> Pop(forward_list <string> stack, int*size)
{
    int j = *size - 2;
    auto places = stack.begin();
    for (int i = 0; i < j; i++)
    {
        places++;
    }
    stack.erase_after(places);
    *size -= 1;
    return stack;
}

void ShowListStack(forward_list <string> stack, int size)
{
    cout << "Все элементы очереди: " << endl;
    auto places = stack.begin();
    while (!stack.empty())
    {
        places = stack.begin();
        if (size == 1)
        {
            cout << *places << endl;
            break;
        }
        int j = size - 2;
        for (int i = 0; i < j; i++)
        {
            places++;
        }
        places++;
        cout << *places << endl;
        stack.erase_after(places);
        size -= 1;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cin >> number;
    switch (number)
    {
        case 1:
        {
            cout << "\n--------------------1--------------------\n" << endl;
            queue<int> queue;
            queue = FillQueue(queue);
            ShowQueue(queue);
            double sum = 0;
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                sum += queue.front();
                queue.pop();
            }
            cout << "Среднее значение элементов очереди: " << sum / size << endl;
            cout << "\n--------------------2--------------------\n" << endl;
            stack<string> stack;
            cout << "Введите по образцу: Название книги - страница" << endl;
            stack = FillStack(stack);
            ShowStack(stack);
            cout << "Количество книг в стеке: " << stack.size() << endl;
            break;
        }
        case 2:
        {
            cout << "\n--------------------1--------------------\n" << endl;
            forward_list<double> queue{0.1};
            int size = 1;
            queue = Enqueue(queue, &size, 2.2);
            queue = Enqueue(queue, &size, 3.2);
            queue = Enqueue(queue, &size, 2.4);
            queue = Enqueue(queue, &size, -3.2);
            ShowListQueue(queue);
            queue = Dequeue(queue, &size);
            queue = Enqueue(queue, &size, 0.04);
            ShowListQueue(queue);
            double sum = 0;
            while (!queue.empty())
            {
                if (abs(queue.front()) < 1)
                {
                    sum += queue.front();
                }
                queue = Dequeue(queue, &size);
            }
            cout << "Сумма чисел, по модулю меньших 1: " << sum << endl;
            cout << "\n--------------------2--------------------\n" << endl;
            forward_list<string> stack{"1"};
            size = 1;
            stack = Push(stack, &size, "111");
            stack = Push(stack, &size, "2");
            stack = Push(stack, &size, "sdf4");
            stack = Push(stack, &size, "bye");
            ShowListStack(stack, size);
            stack = Pop(stack, &size);
            ShowListStack(stack, size);
            auto places = stack.begin();
            int maxim = 0;
            string temp;
            while (!stack.empty())
            {
                places = stack.begin(); 
                if (size == 1)
                {
                    maxim = maxim < (int)temp.size() ? temp.size() : maxim;
                    break;
                }
                int j = size - 2;
                for (int i = 0; i < j; i++)
                {
                    places++;
                }
                places++;
                temp = *places;
                maxim = maxim < (int)temp.size() ? temp.size() : maxim;
                stack.erase_after(places);
                size -= 1;
            }
            cout << "Максимальный размер строки в стеке: " << maxim << endl;
            break;
        }
        case 3:
        {
            cout << "\n--------------------1--------------------\n" << endl;
            queue<int> queue1;
            queue<int> queue2;
            queue1 = FillQueue(queue1);
            queue2 = FillQueue(queue2);
            cout << "Первый и последний элементы первой очереди: " << queue1.front() << " - " << queue1.back() << " Первый и последний элементы второй очереди: " << queue2.front() << " - " << queue2.back() << endl;
            while (!queue1.empty())
            {
                if (queue1.front() % 2 == 0)
                {
                    break;
                }
                queue2.push(queue1.front());
                queue1.pop();
            }
            if (queue1.empty())
            {
                cout << "Первый и последний элементы первой очереди: " << "nil - nil" << " Первый и последний элементы второй очереди: " << queue2.front() << " - " << queue2.back() << endl;
                break;
            }
            cout << "Первый и последний элементы первой очереди: " << queue1.front() << " - " << queue1.back() << " Первый и последний элементы второй очереди: " << queue2.front() << " - " << queue2.back() << endl;
            break;
        }
        case 4:
        {
            cout << "\n--------------------1--------------------\n" << endl;
            forward_list<double> list;
            list = FillForList(list);
            ShowForList(list);
            forward_list<double> newList;
            int skip = 0;
            for (auto i = list.begin(); i != list.end(); i++)
            {
                if (skip)
                {
                    skip = 0;
                    continue;
                }
                if (*i > 0)
                {
                    skip = 1;
                }
                newList.push_front(*i);
            }
            list.clear();
            for (auto i = newList.begin(); i != newList.end(); i++)
            {
                list.push_front(*i);
            }
            ShowForList(list);
            list.clear();
            newList.clear();
            cout << "\n--------------------2--------------------\n" << endl;
            list = FillForList(list);
            list.pop_front();
            for (auto i = list.begin(); i != list.end(); i++)
            {
                newList.push_front(*i);
            }
            newList.pop_front();
            list.clear();
            for (auto i = newList.begin(); i != newList.end(); i++)
            {
                list.push_front(*i);
            }
            if(list.begin() != list.end()) 
            ShowForList(list);
            break;
        }
        case 5:
        {
            cout << "\n--------------------1--------------------\n" << endl;
            list<int> newList;
            list<int> list;
            list = FillList(list);
            int skip = 0;
            for (auto i = list.begin(); i != list.end(); i++)
            {
                if (skip)
                {
                    skip = 0;
                    continue;
                }
                if (*i == 4)
                {
                    skip = 1;
                }
                if (*i == 1)
                {
                    newList.push_back(*i);
                    newList.push_back(0);
                    continue;
                }
                newList.push_back(*i);
            }
            ShowList(newList);
            cout << "\n--------------------2--------------------\n" << endl;
            forward_list<char> forList;
            forward_list<char> newForList;
            forList = FillForList(forList);
            skip = 0;
            for (auto i = forList.begin(); i != forList.end(); i++)
            {
                if (skip)
                {
                    skip = 0;
                    continue;
                }
                if (*i ==  '^')
                {
                    skip = 1;
                }
                newForList.push_front(*i);
            }
            int count = 0;
            ShowForList(newForList);
            for (auto i = newForList.begin(); i != newForList.end(); i++)
            {
                if (*i == '*')
                {
                    count += 1;
                }
            }
            cout << "Количество *: " << count << endl;
            break;
        }
        case 6:
        {
            list<int> newList;
            list<int> list;
            list = FillList(list);
            int pk;
            cout << "Введите позицию элемента: " << endl;
            cin >> pk;
            int k;
            cout << "Введите новую позицию элемента: " << endl;
            cin >> k;
            int tmp;
            int num = 1;
            for (auto i = list.begin(); i != list.end(); i++)
            {
                if (num == pk)
                {
                    tmp = *i;
                    num++;
                    continue;
                }
                if (num == pk+k)
                {
                    newList.push_back(tmp);
                }
                newList.push_back(*i);
                if (i == list.end() && num < pk + k)
                {
                    newList.push_back(tmp);
                    break;
                }
                num++;
            }
            ShowList(newList);
            cout << "Первый и последний элементы: " << list.front() << " - " << list.back();
            break;
        }
        default:
        {
            cout << "Такого номера нет";
            break;
        }

    }
    return 0;
}