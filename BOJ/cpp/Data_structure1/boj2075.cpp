#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

void pushWithMax(int i, int cnt)
{
    while (pq.size() < cnt)
    {
        pq.push(i);
    }
    if (i > pq.top())
    {
        pq.pop();
        pq.push(i);
    }
};
int pqSolve()
{
    int cnt;
    cin >> cnt;

    int N = cnt * cnt;
    // minHeap n개로 이뤄진

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        // cout << arr[i] << endl;
        pushWithMax(arr[i], cnt);
    }

    cout << pq.top();

    return 0;
}

int sortBruteForce()
{
    int cnt;
    cin >> cnt;
    int arr[cnt * cnt];

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            cin >> arr[cnt * i + j];
        }
    }

    sort(arr, arr + cnt * cnt);
    cout << arr[cnt * cnt - cnt];

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pqSolve();
    return 0;
}