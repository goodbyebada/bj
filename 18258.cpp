#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string command;
    int q_num;

    cin >> N;

    queue<int> q;

        for (int i = 0; i < N; i++)
    {

        cin >> command;

        if (command == "push")
        {
            cin >> q_num;
            q.push(q_num);
        }
        else if (command == "pop")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (command == "size")
        {
            cout << q.size() << '\n';
        }
        else if (command == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (command == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else
        {
            if (!q.empty())
            {
                cout << q.back() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
}
