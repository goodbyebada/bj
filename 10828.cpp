#include <iostream>
#include <stack>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string command;
    int push_num;
    stack<int> stack;

    cin >> N;

    while (N--)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> push_num;
            // cout << "정상작동";
            stack.push(push_num);
        }
        else if (command == "pop")
        {

            if (stack.empty())
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << stack.top() << "\n";
                stack.pop();
                // 맨 위 점수 출력 후 삭제
            }
        }
        else if (command == "size")
        {
            cout << stack.size() << "\n";
        }
        else if (command == "empty")
        {
            if (stack.empty())
            {
                cout << "1"
                     << "\n";
            }
            else
            {
                cout << "0"
                     << "\n";
            }
        }
        else if (command == "top")
        {
            if (stack.empty())
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << stack.top() << "\n";
            }
        }
    }

    return 0;
}