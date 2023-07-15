#include <iostream>
#include <stdlib.h>
#include <string.h>
// for strcmp
using namespace std;
int front = 0;
int top = 0;

void push(int *q)
{
    int push_num;
    cin >> push_num;
    q[top] = push_num;
    top++;
}

int size(int *q)
{
    return top - front;
}

void pop(int *q)
{
    if ((top - front) != 0)
    {
        cout << -1;
    }
    else
    {
        cout << q[front];
        front++;
    }
}

int empty(int *q)
{
    if (!size(q))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int front_Fun(int *q)
{
    if (empty(q))
    {
        return -1;
    }
    return q[front];
}

int back_Fun(int *q)
{
    if (empty(q))
    {
        return -1;
    }

    return q[top - 1];
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string command;
    // int arr[50];

    cin >> N;
    int *q = (int *)malloc(sizeof(int) * N);

    while (N--)
    {

        cin >> command;

        if (command == "push")
        {
            push(q);
        }
        else if (command == "pop")
        {
            pop(q);
        }
        else if (command == "size")
        {
            cout << size(q) << endl;
        }
        else if (command == "empty")
        {
            cout << empty(q) << endl;
        }
        else if (command == "front")
        {
            cout << front_Fun(q) << endl;
        }
        else if (command == "back")
        {
            cout << back_Fun(q) << endl;
        }
    }

    free(q);
}