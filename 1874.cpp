#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 문제 1이 사라질 때 예외처리를 못 하겠음

// 1. 경우의 수 3가지로 나눔
// 2. 1이 사라질 때 예외처리를 못 하겠음 -> + 가 뜨지 않고 바로 NO가 떠야함
// 어떻게 구분할 것인가? tmp 로 도전
// 반례 : 1 2 3 4 있는데 pop 계속해서 1만 남아잇는 상태 입력값이 6이라면?
//  1 5 6 후 6 pop해야함

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

    if (cin_q.front() == 1 && (tmp == 1))
    {
        cout << "NO\n";
        return 0;
    }

    int i = 1;
    s.push(i);
    cout << "+" << '\n';
    // 최초 1회

    while (!cin_q.empty())
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
            cin_q.pop();

            cout << "-" << '\n';
            //- 출력 후 종료
        }
        tmp++;
    }
}
