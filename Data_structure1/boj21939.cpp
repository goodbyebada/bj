#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define endl '\n'
using namespace std;

/*
1s

1h

{문제번호, 문제 난이도}
1. recommand 1 : 제일 어려운 난이도의 문제를 출력, 난이도가 동일한 것이 여러개라면 문제번호가 큰 것 출력
2. recommand -1 : 제일 쉬운 난이도의 문제를 출력, 난이도가 동일한 것이 여러개라면 문제번호가 작은 것 출력
3. add P L : 문제번호 p, 난이도가 L 을 추가
리스트에 없는 문제라면 문제번호 p만 들어올 수 있고, 리스트에 있는 문제라면 L  다른 난이도로 들어온다
4.solved P: 추천 번호 리스트 p 제거

명령어 recommend는 추천 문제 리스트에 문제가 하나 이상 있을 때만 주어진다
명령어 solved는 추천 문제 리스트에 문제 번호가 하나 이상 있을 때만 주어진다.

처음 주어지는 문제 리스트 => N개 최대 100000  => 10**5 -> 1초 안됨
이후 추가 , 삭제 => 최대 10000


sol 1)
1. 주어진 {문제번호, 난이도}를 vec에 push
2. sort => 난이도가 같다면 문제번호가 큰 순으로 내림차순으로 정렬
3. add -> 리스트에 있는 문제라면 난이도만 변경,
없다면 push_back 후 sort
4. recommand => 내림차순으로 정렬할 것이기에 1이라면 vec[1], -1 이라면 [-1] 출력
5. solved -> 이분탐색하면 되잖아 nlogN
{0,0} 으로 초기화 , sort , 인덱스 -1에서부터 >0인 수가 나올때까지 pop_back

=> 시간초과
1) add + sort nlogn -> n번 반복한다면 n*nlogn 1초 넘어감
2) solved 탐색 logN 초기화 + 정렬 logN  n*nlogn 

----답지 봄

map (레드블랙트리) :  O(log n)의 시간 복잡도로 삽입, 삭제, 검색



*/
vector<pair<int, int> > v;
queue<int> ans;

//  내림차순 난이도 먼저 -> 같다면 문제 번호 {문제번호 , 난이도 }
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}

// 내림차순용 바이너리 서치
void binary_search(vector<pair<int, int> > &v, int target)
{

    int low = 0;
    int high = v.size() - 1;

    while (high - low >= 0)
    {
        int mid = (low + high) / 2;

        if (v[mid].first < target)
        {
            high = mid - 1;
        }
        else if (v[mid].first > target)
        {

            low = mid + 1;
        }
        else
        {
            // v[mid] == target
            // cout << "문제 찾음" << v[mid].first << endl;
            v[mid] = {0, 0};
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int name, lev;

    while (n--)
    {
        cin >> name >> lev;
        v.push_back({name, lev});
    }

    sort(v.begin(), v.end(), comp);
    // 내림차순 정렬

    int tmp;
    cin >> tmp;

    while (tmp--)
    {
        string str;
        cin >> str;

        int P, L, x;

        if (str[0] == 'a')
        {
            cin >> P >> L;
            v.push_back({P, L});
            sort(v.begin(), v.end(), comp);
        }
        else if (str[0] == 's')
        {
            // soleved
            cin >> P;
            binary_search(v, P);
            sort(v.begin(), v.end(), comp);
            v.pop_back();
        }
        else
        {
            // 'r'일때
            cin >> x;
            if (x > 0)
            {
                cout << v[0].first << endl;
            }
            else
            {
                cout << v.back().first << endl;
            }
        }
    }

    return 0;
}
