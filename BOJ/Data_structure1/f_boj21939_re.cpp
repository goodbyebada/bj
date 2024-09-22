
/*
9:58 ~

**문제:

1. recommend x :
x == 1 : 제일 어려운 문제 , 여러개라면 번호가 가장 큰 것
x == -1 : 제일 쉬운 문제, 여러개라면 번호가 가장 작은 것
2. add P L : 문제번호 P, 난이도가 L 추가한다.
P만 있다면, 문제리스트에 없는 문제
P L : 존재하는 문제 번호가 다른 난이도로 들어올 수 있다.
3. solved P : 문제번호 P 제거

명령어 recommend는 추천 문제 리스트에 문제가 하나 이상 있을 때만 주어진다.
명령어 solved는 추천 문제 리스트에 문제 번호가 하나 이상 있을 때만 주어진다.

4. 입력
문제의 개수 : N
N+1 줄부터 P L 공백으로 구분
N+2 줄부터 명령어 개수 M
5. 출력 조건 : recommend 명렁이 주어질때마다 문제 번호 한 줄 씩 출력

**sol)
1. 문제 난이도에 따른 정렬  pair => {난이도, 문제번호}
2. 삽입될때마다 정렬 O(n^2) -> 시간초과

**sol2)
1. 큐를 두 개 사용하자
2. 최대힙 , 최소힙 -> 삽입, 삭제 : O(log n)
3. 삭제 후 정렬 ..?


*/

// priority_queue<pair<int, int>> up_pq;
// // 내림차순 p, 어려운 문제순으로
// priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> down_pq;
// // 오름차순 pq 쉬운 문제순으로

// 다른 사람 코드
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> max_pq;
// 내림차순 p, 어려운 문제순으로
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
// 오름차순 pq 쉬운 문제순으로

map<int, int> _map;

int n, m;

void _remove()
{
    // pq들의 top에 있는 문제가 이미 푼 문제라면 삭제한다.
    // map[N] = 0 이라면 푼 문제
    while (_map[max_pq.top().second] == 0)
    {
        max_pq.pop();
    }

    while (_map[min_pq.top().second] == 0)
    {
        min_pq.pop();
    }
    // 매번 체크하기 때문에 이미 푼 문제를 추천할 일이 없다
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        _map[a] = 1;
        //  map 이용해 두 우선순위 큐를 동기화 해줘야함

        max_pq.push(make_pair(b, a));
        min_pq.push(make_pair(b, a));
    }

    cin >> m;

    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s;

        // 매회 pq에 있는 허수값들을 삭제한다.
        _remove();

        if (s == "add")
        {
            cin >> b >> c;
            // 문제 번호, 난이도
            _map[b] = 1;
            max_pq.push(make_pair(c, b));
            min_pq.push(make_pair(c, b));
            // 난이도 , 문제번호 삽입
        }
        else if (s == "recommend")
        {
            cin >> b;

            // 이미 푼 문제들은 pq에서 삭제한다
            if (b == 1)
            {
                cout << max_pq.top().second << '\n';
            }
            else if (b == -1)
            {
                cout << min_pq.top().second << '\n';
            }
        }
        else if (s == "solved")
        {
            cin >> b;
            _map[b] = 0;
        }
    }

    return 0;
}
