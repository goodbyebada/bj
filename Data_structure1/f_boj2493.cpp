#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

/*
04:02~4:40

1. 탑은 왼쪽으로 수신한다
2. 레이저를 보내는 탑의 높이보다 같거나 작은 높이의 탑이 존재한다면, 가장 가까이에 있는 탑이 레이저를 받는다
3. 앞에 레이저를 보내는 탑보다 높이가 작다면 0개의 탑이 수신받는다.

1) BrutForce -> O(n*n)=> 1.5초..? 시간초과 ㅎ
1. 배열 두개
1) 탑의 키 배열에 넣기 -> 큰 곳에서 작은 곳으로 인덱스 줄이면서 검사
2) 수신 받은 전봇대 키 넣는 배열

12:46~ 13:03

 */

// struct info
// {
//     int h, num;
// };

vector<pair<int, int>> v;
stack<pair<int, int>> s;
vector<int> ans;

// 최댓값 스택에 넣기

int boj()
{

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i + 1});
    }

    s.push({0, 0});

    // 스택에 info를 넣는다
    // 현재 s.top().h <= v[i].h , pop() 하고 s.top().h 가 최대높이, ans에 저장하고 s에 현재값을 push한다.
    //  아니라면, 현재 s.top().h 최대 높이 ans에 num을 기록하고 , push한다

    for (int i = 0; i < v.size(); i++)
    {

        while (s.top().first <= v[i].first)
        {
            if (s.size() > 1)
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        ans.push_back(s.top().second);
        s.push(v[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

int test()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // boj();

    return 0;
}