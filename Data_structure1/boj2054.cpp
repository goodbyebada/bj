#include <iostream>
#include <stack>
using namespace std;

/*
1. 스택 사용
2. 하나씩 받는다
3. 괄호가 완성되면 숫자로 넣는다
4. 닫는 괄호가 들어올때 여는 괄호가 나올때까지 빼놓는다
5. 숫자가
이때, 처음으로 만난 여는 괄호가 짝이 안맞으면(없을수도 있)? -> 잘못된 경우


 */

stack<int> st;
stack<int> result;
int boj2054()
{

    char c;

    cin >> c;
    st.push(c);
}

int find(char c)
{
    if (c == ')')
    {
        while (st.top() != '(')
        {
            int topNum = st.top();
            st.pop();
            result.push(topNum);
        }
    }

    else if (c == ']')
    {
    }
}

int pair(char c)
{
    if (c == ')'){
        st.
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj2054();
}