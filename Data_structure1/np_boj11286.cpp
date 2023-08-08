#include <iostream>
#include <queue>
using namespace std;

struct comp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        // 절댓값이 같으면 a>b true 반환, 오름차순으로 정렬
        else
            return abs(a) > abs(b);
        // 절댓값이 같지 않다면 절댓값이 클 때 true 반환 , 오름차순으로 정렬
    }
};

void Solution(int n)
{
    priority_queue<int, vector<int>, comp> pq;
    // pq 정렬
    // 절댓값이 작은 순대로 정렬

    while (n--)
    {
        int Command;
        cin >> Command;

        if (Command == 0)
        {
            if (pq.empty())
            {
                cout << '0' << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(Command);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Solution(n);

    return 0;
}