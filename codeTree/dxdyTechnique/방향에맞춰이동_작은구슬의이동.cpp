#include <iostream>
using namespace std;
#include <utility>
#include <unordered_map>

/*
6:02~6:27

1. 방향 바꾸기 위해 합 3으로 만들어준다
위, 아래 = 2, 1
오른쪽, 왼쪽 = 0, 3

2. 배열에 없는 인덱스라면, 방향을 바꿔준다
입력: 격자크기 n 시간 t == t만큼 이동
        r행 c열 d 방향을 바라보고 있다

*/

bool inRange(int x, int y, int max)
{
    // cout << "inRange" << x << " " << y << endl;
    return (0 <= x && x < max && 0 <= y && y < max);
}

int main()
{
    // 여기에 코드를 작성해주세요.

    // 위, 아래 = 2, 1
    // 오른쪽, 왼쪽 = 0, 3

    int arrNum = 0, moveCnt = 0;

    cin >> arrNum >> moveCnt;

    // 오른쪽 , 아래 , 위, 왼쪽
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    unordered_map<char, int> myMap = {{'R', 0}, {'D', 1}, {'U', 2}, {'L', 3}};

    int x, y;
    // 현재 좌표
    char dir_char;
    // 처음 방향
    cin >> x >> y >> dir_char;

    // 인덱스 맞추기 위해
    x -= 1;
    y -= 1;

    // 처음에만
    int dir_num = myMap[dir_char];

    while (moveCnt--)
    {
        int ix = x + dx[dir_num];
        int iy = y + dy[dir_num];
        // 이동할 좌표

        if (!inRange(ix, iy, arrNum))
        {
            // 이동할 좌표 유효하지 않다면 방향만 바꾼다
            dir_num = 3 - dir_num;
            continue;
        }

        // 유효다면 예상 좌표를 배정한다.
        x = ix;
        y = iy;
    }

    cout << x + 1 << " " << y + 1;

    // 코드 줄이고 싶어서 inRange(x+= dx[dir_num], y += dy[dir_num], arrNum) 함 ㅋㅋ..
    //  연산이 된다..

    return 0;
}