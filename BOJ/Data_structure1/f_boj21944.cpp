#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

/*
10:28~

1. recommand G x :
알고리즘 문제  종류가 G
x=1 가장 어려운 문제번호를, 동일 조건시 가장 큰 문제 번호를
x=-1 가장 쉬운 문제 번호를, 동일 조건시 가장 작은 문제 번호를

2) recommand2 x
x=1 가장 어려운 문제번호를, 동일 조건시 가장 큰 문제 번호를
x=-1 가장 쉬운 문제 번호를, 동일 조건시 가장 작은 문제 번호를

3) recommand3 x L
>= L, 문제 번호가 작은 것으로 출력, 여러개라면 가장 문제 번호가 작은것으로 출력
< L , 문제 번호가 큰 것으로 출력 , 여러개라면 가장 문제 번호가 큰 것으로 출력
만족하지 않는다면 -1 출력

4) add P L G
문제번호 P 난이도 L 알고리즘 G -> 문제집에 있는 문제번호 다른 난이도, 다른 알고리즘으로 들어올 수 있다

5) solved P
P번 제거

N 100000 -> 삽입될 문제 개수
M 10000 -> 실행될 명령어


N+M 100000
sol1)
{P L G} -> 속성대로 정렬
1. 종류별 우선순위  큐를 만든다 -> 해당 G, L 이 나올때까지 pop시켜야함 => 삭제됨
레벨 기준
알고리즘 기준


2.
난이도와 알고리즘에 따라 출력하는것이라면

일단 난이도에 따른 우선순위 큐 2개 (오름차순, 내림차순 순으로), 맵을 통해 확인해 허수인 수를 없앤다 -> 난이도를 기준으로 정렬
                                                                             -> 알고리즘
알고리즘
<> -> vector O(NlogN) 처음과 끝
2 ->
3 ->

알고리즘 종류에 따른 우선순위 큐 -> 벡터에 난이도 기준으로 정렬 + -> 우선순위 큐를 가리키고 ( 최소 / 최대  ) 각 두개씩..?
한 벡터 정렬 100000* log(100000) + 100000 -> 1초..?

*/

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minPQ;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> maxPQ;

pair<int, pair<int, int>> put;
map<int, int> _map;

void _remove()
{

    while (_map[minPQ.top().second.second] == 0)
    {
        minPQ.pop();
    }

    while (_map[maxPQ.top().second.second] == 0)
    {
        maxPQ.pop();
    }
}

int myboj()
{
    int N;
    int P, L, G;

    cin >> N;

    while (N--)
    {
        cin >> P >> L >> G;

        // 난이도, 알고리즘 , 문제번호
        minPQ.push({L, {G, P}});
        maxPQ.push({L, {G, P}});
        _map[P] = 1;
    }

    int M;

    string op;

    cin >> M;

    while (M--)
    {
        int G, L, x;

        _remove();

        if (op == "recommand")
        {
            // 알고리즘 종류별에 따른 문제 추천
            cin >> G >> x;

            if (x == 1)
            {
                //
            }
            else
            {
            }
        }
        else if (op == "recommand2")
        {
            cin >> x;
            if (x == 1)
            {
            }
            else
            {
            }
        }
        else if (op == "recommand3")
        {
        }
        else if (op == "solved")
        {
            cin >> P;
            _map[P] = 0;
        }
    }
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     // myboj();
//     return 0;
// }

#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
#define X first
#define Y second

set<pair<int, int>> algorithm[101]; // 알고리즘 : set({난이도, 문제번호})
set<int> level[101];                // 난이도 : set(문제번호)
pair<int, int> problem[100001];     // 문제번호 : {난이도, 알고리즘}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--)
    {
        int p, l, g;
        cin >> p >> l >> g;
        algorithm[g].insert(make_pair(l, p));
        // algorithm[알고리즘 번호 ] insert((레벨, 문제 번호 ))
        level[l].insert(p);
        // level[레벨] insert(문제번호)
        problem[p] = make_pair(l, g);
        // 문제 - 난이도 알고리즘
    }

    int M;
    cin >> M;
    int a, b, c;

    while (M--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "recommend")
        {
            cin >> a >> b;
            if (b == 1)
            {
                auto pr = *prev(algorithm[a].end());
                cout << pr.Y << '\n';
            }
            else
            {
                auto pr = *algorithm[a].begin();
                cout << pr.Y << '\n';
            }
        }
        else if (cmd == "recommend2")
        {
            cin >> a;
            // 난이도에 따른 정렬

            if (a == 1)
            {

                // 제일 어려운 난이도를 위해 뒤에서부터 탐색한다.
                for (int i = 100; i >= 1; i--)
                {
                    if (level[i].empty())
                        continue;
                    // 제일 숫자가 큰 문제를 출력한다.ㄴ
                    cout << *prev(level[i].end()) << '\n';

                    break;
                }
            }
            else
            {
                for (int i = 1; i <= 100; i++)
                {
                    // 제일 쉬운 난이도를 위해 앞에서부터 탐색한다.
                    if (level[i].empty())
                        continue;
                    // 제일 숫자가 작은 문제를  출력한다
                    cout << *level[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (cmd == "recommend3")
        {
            cin >> a >> b;
            int res = -1;
            // 없다면 -1 출력

            // b 난이도

            if (a == 1)
            {
                // b난이도 이상이기 때문에 b부터 시작
                for (int i = b; i <= 100; i++)
                {
                    if (level[i].empty())
                        continue;
                    res = *level[i].begin();
                    break;
                }
            }
            else
            {
                // b 난이도 미만이니까 b-1부터 시작
                for (int i = b - 1; i >= 1; i--)
                {
                    if (level[i].empty())
                        continue;
                    res = *prev(level[i].end());
                    break;
                }
            }
            cout << res << '\n';
        }
        else if (cmd == "add")
        {
            cin >> a >> b >> c;
            algorithm[c].insert(make_pair(b, a));
            level[b].insert(a);
            // set 삽입과 동시에 정렬

            problem[a] = make_pair(b, c);
        }
        else if (cmd == "solved")
        {
            cin >> a;
            int l = problem[a].X;
            int g = problem[a].Y;
            // problem[a] = make_pair(0,0);
            algorithm[g].erase(make_pair(l, a));
            level[l].erase(a);
        }
    }

    return 0;
}

/**
 * 나의 풀이)
 * 우선순위 큐를 사용하려고 했음
 * 최대 큐와, 최소 큐를 사용하려고 했음
 *
 * 풀지못한 이유)
 * 알고리즘에 따른 분류
 * 레벨에 따른 분류
 * 그럼 최대, 최소 큐를 적어도 4개씩 만들어야한다.
 * 그리고 접근이 안된다!
 *
 * 얻은 insight)
 * 1. 분리하자 => 알고리즘에 따른 set, 난이도에 따른 set, 문제번호에 따른 pair(solved를 위한 제거 용도)
 * 2. set 사용하면 탐색/삽입/삭제 O(logN)의 시간
 */