#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
풍선의 개수를 입력 받는다.
이동해야하는 값이 적혀있다.

1. 풍선의 개수 받는다
2. <N번, 쪽지> pair 로 벡터에 push
3. v.front 쪽지만큼 이동한다
이동해야하는 값  = 쪽지 % N
 <0 v.size() - 이동해야하는 값
 >0  이동해야하는 값

 이동후 pop (터진 풍선 )
 인덱스 다른 큐에 저장할거임
 indexQ.push(x) => 마지막에 출력위해

 그 다음 풍선이 front에 올때까지 pop push 반복
 */

int returnNext(int move_num, vector<pair<int, int>> v);
vector<pair<int, int>> getFront(int nextBalllon, vector<pair<int, int>> v);

// vector<pair<int, int>> test = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

int boj2346()
{

    int N;
    // 풍선의 개수
    cin >> N;

    // 벡터에 쪽지, 인덱스 저장
    vector<pair<int, int>> v;
    queue<int> result;

    for (int i = 1; i <= N; i++)
    {
        int move_num = 0;
        cin >> move_num;
        v.push_back(make_pair(move_num, i));
    }

    // 첫번째 풍선 이름

    while (N--)
    {
        result.push(v.front().second);
        // 1.탐색 move_num만큼 이동해서 다음 풍선을 찾는다
        cout << "이동해야할 숫자: " << v.front().first << endl;

        cout << "vSize(): " << v.size() << endl;
        int move_num = v.front().first % v.size();
        cout << "move_num:  " << move_num << endl;

        int nextBallon = 0;

        if (v.empty())
        {
            return 0;
        }

        if (move_num > 0)
        {
            nextBallon = v[move_num].second;
        }
        else
        {
            move_num = v.front().first % v.size();
            cout << "최종 move_num:  " << move_num << endl;
            nextBallon = v[v.size() - move_num].second;
        }

        // 2.다음 풍선을 앞으로 뺀다

        v.erase(v.begin());

        while (v.front().second != nextBallon)
        {
            pair<int, int> now = v.front();

            v.push_back(now);
            v.erase(v.begin());
            // pop()
        }

        // 3.그 풍선의 쪽지를 읽는다

        // 다시 1로 돌아감
    }

    while (!result.empty())
    {
        if (result.size() == 1)
        {
            cout << result.front();
            return 0;
        }
        cout << result.front() << " ";
        result.pop();
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj2346();
}
