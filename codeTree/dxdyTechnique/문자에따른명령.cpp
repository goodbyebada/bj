#include <iostream>
using namespace std;

int main()
{

    /*
    (1, 5) 위치에서 시작하며 현재 북쪽을 바라보고 있습니다.

    방향을 시계방향으로 90' 회전한 후,
    앞으로 한 칸 이동한 이후의 위치를 구해보세요.
    */

    /*
    1. 시계방향으로 90도로 회전했을때 dir_num이 바뀌어야한다.
    2. 앞으로 1만큼 이동해야한다.
    */

    // 동 서 남 북
    // 0 -> 1 -> 2-> 3

    int dir_num = 3;
    int x = 1, y = 5;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
    int nx, ny;

    // rotate direction
    // if (dir_num == 0)
    //     dir_num = 1;
    // else if (dir_num == 1)
    //     dir_num = 2;
    // else if (dir_num == 2)
    //     dir_num = 3;
    // else
    //     dir_num = 0;

    // --> 코드 줄이기
    dir_num = (dir_num + 1) % 4;
    // rotate (X+1)%4 => 0 ->1 넘어갈때 때문에

    // 만약 반시계 방향이라면
    //  dir_num = (dir_num + 3) % 4;

    // move
    nx = x + dx[dir_num], ny = y + dy[dir_num];

    return 0;
}