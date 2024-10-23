#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define endl '\n'
#define X first
#define Y second
#define MAX 500

using namespace std;

/**
 * 그림
 * 실버 1
 * 09:03~ 09:30
 *
 *
 * 출력해야할 것
 * 그림의 개수
 * 그림 중 가장 넓이가 넓은 것
 * 그림이 하나도 없다면, 가장 넓은 그림의 넓이는 0
 *
 * 세로의 크기 1 <= n <= 500
 * 가로의 크기 1 <= m <= 500
 * 0은 색칠이 안됨, 1은 색칠이 된 부분
 *
 * ** 힌트
 * 그림의 넓이 : BFS가 끝난, 큐가 empty가 될때의 개수
 * 그림의 개수 : 이중 for문으로 각 칸의 BFS의 시작점이 될 수 있는지를
 * 해줘야한다.
 *
 * ** 시간 복잡도
 * 모든 칸은 큐에 한번씩만 들억나다. 때문에 O(nm)이다.
 * 1초 안됨
 *
 */

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[MAX][MAX];
int vis[MAX][MAX];
int cnt;
int maxWidth = 0;

int BFS(pair<int, int> startPair) {
  queue<pair<int, int>> Q;
  int width = 0;
  vis[startPair.X][startPair.Y] = 1;
  Q.push({startPair.X, startPair.Y});

  while (!Q.empty()) {
    pair<int, int> curr = Q.front();
    Q.pop();
    width++;

    for (int dist = 0; dist < 4; dist++) {
      int x = curr.X + dx[dist];
      int y = curr.Y + dy[dist];

      if (vis[x][y] == 1 || arr[x][y] == 0) continue;  // 접근불가능한 상태
      if (x < 0 || y < 0 || x >= n || y >= m) continue;  //   범위를 벗어난 상태
      vis[x][y] = 1;
      Q.push({x, y});
    }
  }

  return width;
}
int boj() {
  cin >> n >> m;

  // input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0 || vis[i][j] == 1) continue;
      int width = BFS({i, j});
      cnt++;
      // 최댓값 업데이트
      if (maxWidth < width) maxWidth = width;
    }
  }

  cout << cnt << endl << maxWidth;

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}