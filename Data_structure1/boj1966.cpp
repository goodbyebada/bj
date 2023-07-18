#include <iostream>
#include <queue>
#include <istream>
#include <algorithm>
#include <vector>

// #include <string.h>

using namespace std;

/*
    vector<int> v;
    v.insert(v.begin(), x); 앞에 삽입
    v.insert(v.end(), x); 뒤에 삽입
    v.earse.(v.begin()); 앞에 원소 제거
    v.earse.(v.begin() + 2); index가 2인 원소 제거
    v[x] 참조 가능
*/

// 가장 앞에 있는 원소 중요도 가장 크면 1 리턴
// 아니면 -1
int checkPriority(vector<pair<int, int>> v, int nowPri)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (nowPri < v[i].first)
            return -1;
    }
    return 1;
}

void boj1966()
{

    int N;

    cin >> N;

    while (N--)
    {
        int index, count;
        cin >> count >> index;

        vector<pair<int, int>> v;

        for (int i = 0; i < count; i++)
        {
            pair<int, int> tmp;
            int number;

            cin >> number;
            tmp = make_pair(number, 0);
            v.push_back(tmp);
            // i == index 일때 1로 체크한다
            // q pair로 <number, 1> 넣는다
        }
        // 입력받기 완료
        v[index].second = 1;
        // 1. 가장 앞에 있는 문서 중요도 확인
        // 2. 현재 문서가 가장 높은 중요도인지 확인
        // 3. 맞다면 출력, 아니면 뒤로 배치

        int cnt = 0;

        while (!v.empty())
        {

            pair<int, int> now = v[0];
            v.erase(v.begin());

            int check = checkPriority(v, now.first);

            if (check == 1)
            {
                cnt++;
                if (now.second == 1)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
            {
                v.push_back(now);
            }
        }

        // 처음에 원하는 문서 뭔지 체크할 방법 필요
        // 출력할때마다 counting 필요
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj1966();
    return 0;
}