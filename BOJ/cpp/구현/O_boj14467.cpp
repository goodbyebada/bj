#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
boj14467
2s

1. 소의 번호 (오른쪽, 왼쪽)
방향의 변화가 생긴다면 카운트 해주면 된다
{key, value}

key를 찾고 value가 달라졌다면 cnt++
 */

vector<pair<int, int>> vec;
map<int, int> mymap;
int cnt = 0;

int boj()
{

    int name, direction;

    cin >> name >> direction;

    if (mymap.find(name) != mymap.end())
    {
        if (mymap[name] != direction)
        {
            mymap[name] = direction;
            cnt++;
        }
    }
    else
    {
        mymap[name] = direction;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    while (n--)
    {
        boj();
    }

    cout << cnt;

    return 0;
}