#include <iostream>
#include <stdlib.h>
#include <string.h>
// for strcmp
using namespace std;
int front = 0;
int end = 0;

int size(int *q)
{
    return end - front;
}

int empty(int *q)
{
    if (size(q) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int *q)
{
    int push_num;
    cin >> push_num;
    q[end] = push_num;
    end++;
}

int pop(int *q)
{
    if (empty(q))
        return -1;
    return q[front++];
}

int front_Fun(int *q)
{
    if (empty(q))
        return -1;
    return q[front];
}

int back_Fun(int *q)
{
    if (empty(q))
        return -1;
    return q[end - 1];
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
            cout << pop(q) << '\n';
        }
        else if (command == "size")
        {
            cout << size(q) << '\n';
        }
        else if (command == "empty")
        {
            cout << empty(q) << '\n';
        }
        else if (command == "front")
        {
            cout << front_Fun(q) << '\n';
        }
        else if (command == "back")
        {
            cout << back_Fun(q) << '\n';
        }
    }

    free(q);
}