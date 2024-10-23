#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define X first;
#define Y second;

/**
 * 미로 탐색
 * 실버 1
 *
 * 1은 이동할 수 있는 칸
 * 0은 이동 불가
 * (N,M) 위치로 이동할때 지나는 최소한의 칸 수를 구해야한다.
 *
 *
 ** 접근 막힌 이유
 * 1. BFS에서 지나는 최소한의 칸 수라는 부분이 이해가 가지 않았다.
 * 무작위로 탐색하지 않고 한번 방문한 노드를 다시 방문하지 않기 때문에
 * 최단경로를 구하는데 적합하다.
 * 2. char to int?
 *
 */

int n, m;
string input;
char board[102][102];
int dist[102][102];
queue<pair<int, int>> Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int boj() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) fill(dist, dist + m, -1);
  // 초기화

  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < m; j++) {
      board[i][j] = input[j];
    }
  }

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  dist[0][0] = 0;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  cout << dist[n - 1][m - 1] + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}