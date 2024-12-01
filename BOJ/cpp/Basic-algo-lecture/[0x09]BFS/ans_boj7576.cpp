
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define X first
#define Y second

/**
 * 모든 시작 점에 대해 BFS를 넣으면 O(NM * NM)이 된다.  => 시간 초과
 *
 * 익은 토마토가 있는 모든 시작점을 큐에 넣고 BFS를 돌린다.
 * dist 배열을 만들어 거리를 기록한다.
 * dist 배열을 통해 방문여부도 알 수 있다.
 *
 * 큐에 쌓이는 순서는 거리순이다.
 *
 */

int n, m;

int dist[1001][1001];
int box[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int> > Q;
pair<int, int> curr;

void BFS() {
  while (!Q.empty()) {
    curr = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      if (x < 0 || y < 0 || x >= n || y >= m) continue;
      if (dist[x][y] >= 0) continue;
      //   익은 토마토, 빈 공간일때는 건너뛴다.

      Q.push({x, y});
      //   큐에 들어간 좌표들은  익은 토마토이다.
      dist[x][y] = dist[curr.X][curr.Y] + 1;
    }
  }
}

// 가장 먼 길이를 구하는 것

int boj() {
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];

      if (box[i][j] == 1) Q.push({i, j});
      if (box[i][j] == 0) dist[i][j] = -1;
      //   익지 않은 토마토 -1로 초기화
      //   익은 토마토, 빈 공간은 거리가 0이다.
    }
  }

  BFS();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == -1) {
        // BFS 이후에도 익지 않은 토마토가 있다며 -1을 출력한다.
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}