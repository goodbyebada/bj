#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
silver 4. 1s
8:49~

1) 좋은단어 세기
- AB
-ABAB -X
- AABB
- ABBA

=> 괄호 문제랑 똑같다!

단어는 문자열로 받는다

1) 스택을 만든다
2) 스택에 넣는다
3) 스택 ToP 과 현재 s[i]가 같다면 pop한다
4) 다르다면 push


2) N <= 100 단어의 길이는  <= 1000000
3) 최대 1초 -> 러프하게 가도 될 듯
 */

int answer = 0;

int sol(string s, int &answer)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    if (st.empty())
    {
        answer++;
    }

    return 0;
}

int boj()
{

    string s;
    int n;

    cin >> n;

    while (n--)
    {
        cin >> s;
        sol(s, answer);
    }

    cout << answer;

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