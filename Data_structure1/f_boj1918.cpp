#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* 후위 표기법

스택..을 써야한다.. 근데 어떻게..?

1)  우선순위 어떻게 판단
2) 괄호는 어떻게 해야함?
3) 후위 표기법 잘못알고 있었음
생각이 꼬이면 바로 찾아보자...
=> ab*c* 가 정답이다 !! abc**가 아녀!!!
-------------------------------------------
1) 문자는 바로 출력한다
2) 연산자는 스택에 push한다.

우선 순위가 있기 때문에,
현재 연산자와 st.top()과 비교해야한다.

3) 우선 순위: 현재 연산자 <= st.top()
- stack이 empty가 될때까지 st.top()과 비교해서 출력/pop()
- 현재 연산자가 st.top()보다 우선순위가 높거나, empty가 되면
멈춘다

4)우선 순위: 현재 연산자 > st.top()
- stack에 push한다.

5.')'를 만난다면 '('가 나올때까지 출력/pop()

  */

int boj()
{
    string s;
    stack<char> st;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
            // 문자라면 출력한다
        }
        else
        {

            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                {
                    // 스택을 비워야함
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!st.empty() && st.top() != '(')
                {
                    // 제일 우선 순위가 낮은 연산자
                    // 차있다면 무조건 비워야한다
                    // 단 ( 가 존재한다면 괄호 전까지 비워야한다!
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {

                while (1)
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        break;
                    }
                    cout << st.top();
                    st.pop();
                }

                // while (!st.empty() && st.top() != '(')
                // {
                //     cout << st.top();
                //     st.pop();
                // }
                // st.pop();
                // ( 제거
            }
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}