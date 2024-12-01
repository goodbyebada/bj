/**
 * 중앙값 구하기 문제
 *
 * 1. 홀수번째일때마다 오름차순으로 정렬한뒤, 중앙값을 출력해야한다.
 * 2. 1000 9999
 * 3. set O(log n ) 100 * 1000 1초 미만
 *
 * sol1)
 * 1. 큐를 이용해 모든 값을 받는다
 * 2. 홀수번째일때 set에 insert
 * 3. (N(홀수) + 1)/2 출력을 위한 큐에 push한다.
 * --> set 중앙값 접근 못함..
 * -> pop()도 없음
 *
 * 내부 벡터를 하나 만들어서 중앙값만 추출하고 해제하자
 * 어차피 o(N)
 *
 *
 * sol2)
 * 1. 큐를 이용해 모든 값을 받는다
 * 2. 우선순위 큐에 홀수일때 값을 넣는다
 * 3. 홀수일때 top() 출력후 pop() 한다.
 * {1} {2} 3 4 5 6 O(logN)
 * -> 1 2 3
 *
 * => pop하면 이전에 들어와있는 값이 사라진다
 * -3 이 들어오면 -3 1 2 3 4 5로 정렬 이때의 중앙값을 구해야한다
 * 중앙값에 어떻게 접근해야할까?
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#define endl '\n'
using namespace std;

queue<int> q;
multiset<int> s;
// priority_queue<int, vector<int>, greater<int>> pq;

void remove()
{
    while (!q.empty())
    {
        q.pop();
    }

    while (!s.empty())
    {
        s.clear();
    }
}

int returnMid()
{
    vector<int> v;

    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
    {
        v.push_back(*iter);
    }

    return v[(v.size() - 1) / 2];
}

int boj()
{
    int N, len;
    cin >> N;

    while (N--)
    {
        cin >> len;

        // 새로운 배열 받기 위한 초기화
        remove();

        // 배열 받기
        for (int i = 1; i <= len; i++)
        {
            signed int a;
            cin >> a;
            q.push(a);
        }

        cout << (q.size() + 1) / 2 << endl;

        for (int i = 1; i <= len; i++)
        {
            s.insert(q.front());
            q.pop();

            // 홀수라면 출력
            if (i % 2 != 0)
            {
                cout << returnMid();
                if (((i + 1) / 2) % 10 == 0)
                {
                    cout << '\n';
                }
                else
                {
                    cout << " ";
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();

    return 0;
}