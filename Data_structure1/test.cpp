#include <iostream>
#include <deque>
using namespace std;

int pqSolve()
{
    int cnt;
    cin >> cnt;

    int arr[cnt];

    for (int i = 0; i < cnt; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pqSolve();
}