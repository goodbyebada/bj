#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int boj10866()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char X[100]; // 충분한 크기의 문자 배열 선언
    deque<int> dq;
    int dq_num;
    int N;

    cin >> N;

    while (N--)
    {

        cin >> X;

        if (strcmp(X, "push_front") == 0)
        {

            cin >> dq_num;
            dq.push_front(dq_num);
        }
        else if (strcmp(X, "push_back") == 0)
        {
            cin >> dq_num;
            dq.push_back(dq_num);
        }
        else if (strcmp(X, "pop_front") == 0)
        {
            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (strcmp(X, "pop_back") == 0)
        {

            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (strcmp(X, "size") == 0)
        {
            cout << dq.size() << '\n';
        }
        else if (strcmp(X, "empty") == 0)
        {
            if (dq.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (strcmp(X, "front") == 0)
        {
            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.front() << '\n';
            }
        }
        else if (strcmp(X, "back") == 0)
        {
            if (dq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.back() << '\n';
            }
        }
    }
    return 0;
}

int main()
{
    boj10866();
    return 0;
}
