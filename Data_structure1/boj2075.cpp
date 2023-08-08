#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int boj()
{
    int cnt;
    cin >> cnt;

    priority_queue<int> pq;
    // greater

    int num1;
    int num2;
    int num3;
    int num4;
    int num5;

    while (cnt--)
    {
        cin >> num1 >> num2 >> num3 >> num4 >> num5;
        pq.push(num1);
        pq.push(num2);
        pq.push(num3);
        pq.push(num4);
        pq.push(num5);
    }

    while (cnt--)
    {
        cout << pq.top();
        pq.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}