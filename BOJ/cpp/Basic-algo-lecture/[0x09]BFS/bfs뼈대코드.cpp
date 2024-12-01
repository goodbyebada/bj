#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define X first
#define Y second

int board[502][502] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};  // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502];  // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10;
// n = 행의 수
// m = 열의 수

// x = 행
// y = 열

// 상하좌우 네 방향을 의미
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/**
 *1. 방문했음을 표시한다.
 *2. 큐에 넣는다.
 *3. pop한다.
 *4. 상하좌우에 접근한다. 갈 수 있다면, 방문했음을 표시하고 큐에 넣는다.
 *5. 큐가 빌때까지 3번으로 돌아가 반복한다.
 */
int boj() {
  queue<pair<int, int>> Q;

  vis[0][0] = 1;
  // (0,0)을 방문했다고 명시
  Q.push({0, 0});
  // 큐에 시작된 점을 삽입.

  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();

    // 상하좌우 칸을 펴본다.
    for (int dir = 0; dir < 3; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      // 범위를 벗어날 경우
      if (nx < 0 || ny >= n || ny < 0 || nx >= 0) continue;
      // 이미 방문한 칸이거나 갈 수 없는 칸일 경우
      if (vis[nx][ny] || board[nx][ny] != 1) continue;

      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}