#include <iostream>
using namespace std;

int n = 4;
int answer[4][4] = {};

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}
// 유효한 좌표인지 확인

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int x = 0, y = 0; // 시작은 (0, 0) 입니다.
int dir_num = 0;  // 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽

int main()
{

    // 1 ~  N*N 숫자 출력해야하니까
    // 처음 시작 위치에 초기값을 적습니다.
    answer[x][y] = 1;

    // n*n번 진행합니다.
    for (int i = 2; i <= n * n; i++)
    {
        // 이동할 예상 방향 좌표
        int nx = x + dx[dir_num], ny = y + dy[dir_num];

        // 방향을 바꾸는 경우 유효하지않은 좌표 || 이미 값을 가진 좌표
        if (!InRange(nx, ny) || answer[nx][ny] != 0)
            dir_num = (dir_num + 1) % 4;

        // 실제로 이동한 찐좌표
        x = x + dx[dir_num];
        y = y + dy[dir_num];

        // 값 넣기
        answer[x][y] = i;
    }

    // 출력:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }

    return 0;
}
