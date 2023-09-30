#include <iostream>
using namespace std;
#include <unordered_map>

// 10:13 ~ 10: 25

/*
1. L -> 왼쪽으로 90도 방향 전환
2. R -> 오른쪽으로 90도 방향 전환
3. F -> 바라보고 있는 방향으로 이동
(0,0) 에서 시작
*/

int sol2()
{

    // dictionary 사용하기
    int x = 0, y = 0;
    string dir_string;
    cin >> dir_string;
    // 동 남 서 북
    //  0 1 2 3
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    int idx = 3;
    // 처음 방향 북쪽

    unordered_map<char, int> dir_map = {{'L', -1}, {'R', 1}, {'F', 0}};

    for (char D : dir_string)
    {
        if (D != 'F')
        {
            idx = idx + dir_map[D];
        }
        else
        {
            // 출력이라면
            x += dx[(idx + 4) % 4];
            y += dy[(idx + 4) % 4];
            cout << x << " " << y;
            return 0;
        }
    }
}

int sol1()
{

    int x = 0, y = 0;
    string dir_string;
    cin >> dir_string;
    // 동 남 서 북
    //  0 1 2 3
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    int dir_num = 3;

    for (int i = 0; i < dir_string.length(); i++)
    {
        if (dir_string[i] == 'L')
        {
            // 반시계방향 90도
            dir_num = (dir_num + 3) % 4;
        }
        else if (dir_string[i] == 'R')
        {
            dir_num = (dir_num + 1) % 4;
        }
        else
        {
            x += dx[dir_num];
            y += dy[dir_num];

            cout << x << " " << y;
            return 0;
        }
    }
}

int main()
{

    // sol1();
    // sol2();
}