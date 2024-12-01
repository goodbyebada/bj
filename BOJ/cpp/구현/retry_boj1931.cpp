#include <algorithm>
#include <iostream>
#include <utility>
#define X first
#define Y second
#define MAX 999

using namespace std;

/**
 * 달팽이
 * 실버 3
 *
 */

// 우 아래 좌 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N;
int arr[MAX][MAX];
int dist = 2;
int num = 1;
int dir = 0;
pair<int, int> ans;

int makeMap(int findNum) {
  int startX = N / 2 - 1;
  int startY = N / 2 - 1;
  //   우 아래 좌 위 를 유지하기 위해 해당 위치에서 출발한다.

  for (int i = 0; i < 4 * (N / 2); i++) {
    // 일정한 거리만큼 가야한다.
    for (int j = 0; j < dist; j++) {
      startX += dx[dir];
      startY += dy[dir];

      arr[startX][startY] = num;
      if (findNum == num) {
        ans.X = startX;
        ans.Y = startY;
      }
      num++;
    }
    dir = (dir + 1) % 4;
    // index가 넘어가지 않게 해야한다.

    // 다시 우 방향이 된다면, 한 바퀴를 다 돌았기에 거리가 더 2만큼
    // 벌어져야한다.
    if (dir == 0) {
      dist += 2;
      //  dir dist 쓰지 않게  주의하자.

      // 처음과 마찬가지로 일관성을 지키기 위해
      startX = startX - 1;
      startY = startY - 1;
    }
  }

  return 0;

  //   다시 시작점으로 돌아간다.
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int findNum;

  cin >> N;
  cin >> findNum;

  arr[N / 2][N / 2] = num;
  if (findNum == num) {
    ans.X = N / 2;
    ans.Y = N / 2;
  }
  num++;

  makeMap(findNum);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }

  cout << ans.X + 1 << " " << ans.Y + 1;

  return 0;
}