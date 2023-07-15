#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int n, k;
    cin >> n >> k;

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    // q에 1~n까지 push

    cout << "<";

    // 문제 해결
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);

            // k-1번째 앞에서 빼서 뒤에서 넣는다
            // k번째 수가 q.front();
            // 큐의 맨앞에 있다
        }
        cout << q.front() << ", ";
        q.pop();
        // 출력 후 pop으로 삭제
    }
    // q에 원소 하나가 남았을때 while문 탈출

    cout << q.front() << ">\n";
    // 마지막 원소까지 출력
}

// 원소를 어떻게 삭제해야할지 pop과 push를 이용해야하는가 고민했었는데,
// k번째가 아닌 수는  변수에 선언 후 pop, push를 이용해 뒤에 삽입함으로 해결하는거였다