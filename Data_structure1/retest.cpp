#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> S1;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ans;
    S1.push({100000001, 0});
    // 가장 큰 값을 넣어놓는다

    int N, max = 0;
    // 최댓값을 0으로 지정 -> 최댓값 얻기 위해

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;

        if (t < max)
        {
            // max는 입력 받은 높이 중 가장 큰 값
            // 앞에 레이더 수신망이 있다는 것
            while (!(S1.empty()))
            {
                if (S1.top().first > t)
                    break;
                // 찾았다!
                else
                    S1.pop();
                // 앞에 있을것이다 pop()시킨다
                // empty 될 일은 없다. 스택 첫번째에 가장 큰 최댓값을 넣어놨으니까
            }
            ans += to_string(S1.top().second);
            ans += " ";
        }
        else
        {
            max = t;
            ans += "0 ";
            // max를 지정해놓으면 0을 빠르게 확정할 수 있다
        }
        S1.push({t, i});
    }
    cout << ans;
}

// 논리는 같은데 시간 차이가 꽤 난다
// 답안 문자열로 배출
// max 값을 설정해 앞에 레이더 받을 전봇대의 유무 먼저 판단한 코드
// -> f_boj2493 (내가 따라한 코드) -> 스택에서 맨 처음 전봇대가 나올때까지 계속 비교해서 찾는다
// empty 될 일은 없다. 스택 첫번째에 가장 큰 최댓값을 넣어놨으니까 -> 안정성 있는 코드인것 같다
// pop하면서 empty일때를 고려를 못해서 오류가 났었음!