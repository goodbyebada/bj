#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define endl '\n'
using namespace std;

/*
숫자 0과 1로만 이루어진 n * n 크기의 격자 상태가 주어집니다.
각 칸 중 상하좌우로 인접한 칸 중 숫자 1이 적혀 있는 칸의 수가 3개 이상인 곳의 개수를 세는 프로그램을 작성해보세요.
단, 인접한 곳이 격자를 벗어나는 경우에는 숫자 1이 적혀있지 않은 것으로 생각합니다

입력:
4
0 1 0 1
0 0 1 1
0 1 0 1
0 0 1 0

답 : 4
*/

bool inRange(int a, int b, int max)
{
    return (0 <= a && a <= max && b <= max && 0 <= b);
    // 조건자체 반환 -> 맞다면 true/ 틀리다면 false
    // 코드 깔끔함
}

int main()
{

    int num;
    cin >> num;

    int arr[num][num];
    int max = num - 1;
    int allCnt = 0;

    // 주어진 값 대입
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 좌표상에서 남 동 북 서 이동방향으로 더해줄 값
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {

            int cnt = 0;
            // 하나의 좌표 cnt

            for (int dir_num = 0; dir_num < 4; dir_num++)
            {
                int nx = i + dx[dir_num];
                int ny = j + dy[dir_num];
                // 남 동 북 서 방향에 따라 움직인 좌표

                if (inRange(nx, ny, max) && arr[nx][ny] == 1)
                {
                    cnt++;
                    // inRange가 우선 유효하다 먼저봐야함 -> 에러 방지
                    // 1이라면 cnt++
                }
            }

            // 4방향 모두 체크 후
            if (cnt >= 3)
            {
                allCnt++;
            }
        }
    }

    cout << allCnt;

    return 0;
}