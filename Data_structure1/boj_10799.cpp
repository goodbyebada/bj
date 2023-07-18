#include <iostream>
#include <stack>

using namespace std;

/*
1. '(' 이후 ')'가 바로 등장하면 레이저
2. 쇠막대기의 조각은 레이저 + 1
3. 쇠막대기는 적어도 () 레이저 하나 존재
4. () 레이저가 존재한다면 쇠막대기 확정
5. 구해야할 것 : 잘려진 조각의 총 개수


풀이 1)
스택 사용
1. ( 스택에 push
2. 바로 ) 가 나온다면 레이저 pop() -> rcnt 효과 x
(() 레이저 카운트
3. 레이저 카운트 rCnt++
4. rCnt >= 1 쇠막대기 확정  -> ) 가 나온다면 쇠막대기 조각 sum += rCnt + 1;

()() (()) 어떻게 구분할 것인가?

 */

int boj_10799()
{
    string s;
    int ans = 0;

    cin >> s;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        { //')'
            if (s[i - 1] == '(')
            { // 레이저인 경우
                st.pop();
                ans += st.size();
            }
            else
            { // 막대의 끝인 경우
                st.pop();
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj_10799();
}

/*
잘못 접근
1. 길이가 작은 쇠막대기부터 조각 개수를 세려고 했음
2. st.size()로 쇠막대기 조각 세면 된다는 점 모름
   레이저가 확정되면, 스택에 들어있는 '(' 의 수가 쇠막대기의 조각이 된다.
3. 괄호를 입력 받는 배열에서 앞 인덱스와 비교를 해야함
    근데 스택에서 비교 처리하려고 함

    마지막 쇠막대기 ) 을 레이저로 판단해버림 ->  ()() (()) 어떻게 구분할 것인가?

한번에 처리하려고 하지말자
 */