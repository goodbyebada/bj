#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

/*
1. 알파벳순으로 정렬 어케함
2. 이름 그만 받는거 어떻게 함
3. 백분율로 바꾸는 거 어케함
-> 넷째자리로 바꾸는 거 어케함
key: 이름 - value: 카운트
 */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int> m;

    string wood;
    // 나무 이름 입력받기 위한 문자열
    int cnt = 0;
    // 총 나무 그루 수

    // getline(cin, wood)-> 백준에서는 입력이 파일로 들어오므로, 해당 함수가 EOF를 읽게 되면 입력이 종료된다
    // cin으로 입력을 받으려고 할 때, EOF라면 입력이 취소된다

    while (getline(cin, wood))
        m[wood]++, cnt++; // 해당 나무 그루 수 1 증가, 전체 나무 수 1 증가

    cout << fixed;
    cout.precision(4); // 소수점아래 넷째자리까지만 표현하도록 고정

    for (auto i = m.begin(); i != m.end(); i++) // 맵 내 전체 원소 출력
        cout << i->first << ' ' << i->second * 100 / (double)cnt << endl;

    // i는 iterator

    return 0;
}

// 내가 하려던 거 - 실패함
int boj()
{

    // 입력 받는 곳
    string s;
    int cnt = 0;
    getline(cin, s);

    cout << s;
    cnt++;
    // s 입력 받을때 카운트 증가

    map<string, int> m;

    for (auto iter : m)
    {
        if (m.find(s) != m.end())
        {
            // 입력받는 s가 map에 있다면
            m[s]++;
            // value 값 증가
        }
        else
        {
            m.insert({s, 1});
            // map에 없다면 새로운 나무 종
        }
    }

    // string 입력받기 끝났다면

    for (auto iter : m)
    {
        cout << iter.first << " " << (double)iter.second / cnt * 100 << '\n';
    }

    return 0;
}