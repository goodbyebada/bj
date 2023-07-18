#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    int stack_num;

    int tmp = 1;

    queue<int> cin_q;
    stack<int> s;

    cin >> N;

    while (N--)
    {
        cin >> stack_num;
        cin_q.push(stack_num);
    }

    int i = 1;
    s.push(i);
    cout << "+" << '\n';
    // s.top()과 비교할거라 1을 먼저 넣음

    N--;

    while (!s.empty())
    {
        if (cin_q.front() > s.top())
        {
            i++;
            s.push(i);
            cout << "+" << '\n';
        }
        else if (cin_q.front() < s.top())
        {
            s.pop();
            cout << "-" << '\n';
        }
        else if (cin_q.front() == s.top())
        {

            s.pop();
            // cout << " 마지막 s.size()" << s.size() << '\n';
            // cout << " 마지막 s.empty()" << s.empty() << '\n';
            cin_q.pop();
            // if (s.empty())
            // {
            //     cout << "NO\n";
            // }
            // else
            // {

            // }

            if (tmp == 1)
            {
                cout << "NO\n";
                return 0;
            }
            cout << "-" << '\n';
            //- 출력 후 종료
        }

        // cout << "현재 s.size()" << s.size() << '\n';
    }

    // cout << "while문을 벗어났어요\n";
}

// while (!q.empty())
// {

//     if (q.front() > s.top())
//     {
//         // q의 front 현재 입력 받은애가 , stack의 top의 값 보다 크다면
//         while (q.front() != s.top())
//         {
//             i++;
//             s.push(i);
//             cout << "+" << '\n';
//             // cout << "현재 s.top()" << s.top();
//         }
//         cout << "stack top():" << s.top() << '\n';
//         // 같아지는 순간
//         s.pop();
//         cout << "-" << '\n';
//         q.pop();
//         cout << "현재 입력 :" << q.front() << '\n';
//         cout << "stack top: " << s.top() << '\n';

//         cout << " q.front() > s.top()" << '\n';
//         break;
//     }
//     else if (q.front() < s.top())
//     {
//         // q의 front 현재 입력 받은애가 , stack의 top의 값 보다 작다면
//         // pop한다
//         cout << " q.front() < s.top()" << '\n';

//         while (q.front() != s.top())
//         {
//             s.pop();
//             // cout << s.top();
//             cout << "-" << '\n';
//         }
//         q.pop();
//     }
//     else
//     {
//         // 같다면

//         // q.pop();
//         // s.pop();
//         // cout << "-" << '\n';

//         // return 0;
//     }
// }