#include <algorithm>
#include <iostream>
#include <queue>
#define X first
#define Y second
#define MAX 100

using namespace std;

char board[MAX][MAX];
int visit[MAX][MAX];
queue<pair<int, int>> Q;
pair<int, int> curr;
int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/**
 *
 *
 * BFS임
 * 첫번째 push한 char과 같고, 방문하지 않은 곳에 방문해야한다.
 */

void BFS(int i, int j, bool challenger) {
  Q.push({i, j});
  visit[i][j] = 1;

  while (!Q.empty()) {
    curr = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = curr.X + dx[i];
      int ny = curr.Y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

      if (challenger) {
        if (visit[nx][ny] == 1) continue;
        if (board[curr.X][curr.Y] == 'B' && board[nx][ny] != 'B') continue;

        // R G 인 경우
        if (board[curr.X][curr.Y] != 'B' && board[nx][ny] == 'B') continue;

      } else {
        if (board[nx][ny] != board[curr.X][curr.Y] || visit[nx][ny] == 1)
          continue;
      }

      Q.push({nx, ny});
      visit[nx][ny] = 1;
    };
  }
}

int boj() {
  // 지역 int 쓰레기값이 들어간다.
  int normal = 0;
  int challenger = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visit[i][j] == 0) {
        BFS(i, j, 0);
        normal++;
      }
    }
  }

  for (int i = 0; i < n; i++) fill(visit[i], visit[i] + n, 0);
  //   초기화

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visit[i][j] == 0) {
        BFS(i, j, 1);
        challenger++;
      }
    }
  }

  cout << normal << " " << challenger;

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}