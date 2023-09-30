#include <iostream>
using namespace std;

int a[5][5] =
    {{0, 0, 0, 1, 0},
     {0, 1, 1, 1, 0},
     {0, 0, 0, 0, 1},
     {1, 0, 1, 1, 1},
     {1, 0, 1, 1, 0}};

int x = 2, y = 4;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y)
{
    return (0 <= x && x < 5 && 0 <= y && y < 5);
}

int main()
{
    int cnt = 0;
    for (int dir_num = 0; dir_num < 4; dir_num++)
    {
        int nx = x + dx[dir_num], ny = y + dy[dir_num];
        if (InRange(nx, ny) && a[nx][ny] == 1)
            cnt++;

        // 조심해야하는 부분
        /*
        if( a[nx][ny] == 1 && InRange(nx, ny))
        격자를 벗어났을때 에러가 뜬다
        왼쪽것부터 먼저 확인하기 때문이다.

        따라서 InRange(nx, ny)가 먼저 와야한다
        방어코드 먼저 와야한다.
        */
    }

    cout << cnt;

    return 0;
}
