#include <queue>
#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> q;
    // 오름차순으로 정렬

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp != 0)
        {
            q.push(tmp);
        }
        else
        {
            if (q.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                // tmp == 0일때 최소 값 출력
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}