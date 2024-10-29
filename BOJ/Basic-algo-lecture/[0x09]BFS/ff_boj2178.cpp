#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define X first
#define Y second

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

void boj() {
  cin >> n >> m;

  // 이차원 배열이니까
  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < m; j++) {
      board[i][j] = input[j];
    }
  }

  dist[0][0] = 0;
  Q.push({0, 0});

  while (!Q.empty()) {
    pair<int, int> curr = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      // dist로 방문 여부를 판단한다.
      if (board[x][y] == '0' || dist[x][y] != -1) continue;
      if (x < 0 || y < 0 || x >= 100 || y >= 100) continue;

      dist[x][y] = dist[curr.X][curr.Y] + 1;
      Q.push({x, y});
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