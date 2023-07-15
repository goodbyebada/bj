#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string command;
    int q_num;
    queue<int> q;

    cin >> N;
    cout << "왜 종료가돼 ";
    cout << N;

    // while (N--)
    for (int i = 0; i < N; i++)
    {
        if (command == "push")
        {
            cin >> q_num;
            q.push(q_num);
        }
        else if (command == "pop")
        {
            q.pop();
        }
        else if (command == "size")
        {
            q.size();
        }
    }

    return 0;
}