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

    cout << "시작" << v.front().second << endl;
    // 첫번째 풍선 이름

    while (N--)
    {
        // 1.탐색 move_num만큼 이동해서 다음 풍선을 찾는다

        int move_num = v.front().first % v.size();
        cout << "move_num : " << move_num << endl;
        int nextBallon = 0;
        nextBallon = returnNext(move_num, v);

        cout << "nextBallon : " << nextBallon << endl;

        // 2.다음 풍선을 앞으로 뺀다
        v = getFront(nextBallon, v);
        // getFront후 맨 앞 애가 삭제가 안됐다.

        cout << " v.front().first: " << v.front().first << endl;

        // 3.그 풍선의 쪽지를 읽는다
        result.push(v.front().first);

        // 다시 1로 돌아감
    }

    while (!result.empty())
    {
        cout << " result에는? ";
        cout << result.front() << endl;
        result.pop();
    }
}

// 다음 N번째 풍선을 탐색하는 함수
int returnNext(int move_num, vector<pair<int, int>> v)
{

    if (move_num > 0)
    {
        return v[move_num].second;
    }
    return v[v.size() - move_num].second;
}

// 다음 N번째 풍선을 front로 빼놓는 함수
vector<pair<int, int>> getFront(int nextBalllon, vector<pair<int, int>> v)
{
    //  이전 풍선은 삭제하고 탐색
    v.erase(v.begin());

    while (v.front().second != nextBalllon)
    {
        pair<int, int> now = v.front();
        cout << "now 쪽지 :" << now.first << endl;
        cout << "now 풍선번호:" << now.second << endl;
        v.push_back(now);
        v.erase(v.begin());
        // pop()
        cout << v.front().second << endl;
    }
    cout << "Getfront 종료" << endl;
    return v;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj2346();
}
