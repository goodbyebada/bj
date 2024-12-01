#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define X first
#define Y second

using namespace std;

/**
 * 불!
 * 골드 3
 *
 *
 * 문제 정리
 * 지훈이와 불은 매분마다 이동한다.
 * 1. 지훈이의 탈출 여부 / 탈출 불가시  IMPOSSIBLE 출력
 * 2. 가능하다면 얼마나 빨리 탈출할 수 있는가
 * 3. 불과 지훈이는 벽을 통과 못한다.
 * 4. 지훈이는 가장자리에 접한 공간에서 탈출 가능
 *
 * # 벽
 * . 지나갈 수 있는 공간
 * J 미로에서의 초기 위치
 * F 불이난 공간
 *
 * 탈출시간 거리순
 * 1. 불과 지훈이의 BFS를 동시에 한다.
 * 2. 마지막에 +1을 붙여준 후 출력
 *
 * # -1
 * . 0
 * 불의 위치 dist -1로 초기화한다.
 * 불의 위치 큐에 넣는다.
 * curr dist의 거리가 -1이라면 불의 위치다.
 * 불은 dist가 0인 곳만 갈 수 있다.
 *
 * 거리가 >=0 이상이라면 지훈이다.
 * 지훈이도 거리가 == 0인곳만 갈 수 있다. 이면 +1 업데이트한다.
 *
 *
 * ** 틀렸습니다.
 * 1. 불과 지훈이의 위치를 같은 큐에 넣었다.
 * 	- 불과 지훈이의 순서가 섞일 수 있다.
 *  - 서로 다른 이동 목적을 가지고 있기 대문에 정보를 독립적으로 관리해야한다.
 * 2. 불이 지나간 자리인지 확인해야한다.
 * 3. 불보다 먼저 이동할 수 있는지 확인해야한다.
 *
 * ** 정답 코드
 * 1. dist1 dist2 모두 -1로 초기화
 * 2. F J 만 0으로 초기화
 * 3. 벽에 대한 예외처리는 board를 통해 한다.
 * .일때 0, #일때 -1으로 분기처리할 필요 없어 간결해진다.
 *
 */

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char character;

int dist1[1001][1001];
int dist2[1001][1001];
char board[1001][1001];
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
pair<int, int> curr;
int r, c;

int boj() {
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    fill(dist1[i], dist1[i] + c, -1);
    fill(dist2[i], dist2[i] + c, -1);
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'F') {
        Q2.push({i, j});
        dist2[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q1.push({i, j});
        dist1[i][j] = 0;
      }
    }
  }

  // 불의 위치
  while (!Q2.empty()) {
    curr = Q2.front();
    Q2.pop();

    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      if (x < 0 || y < 0 || x >= r || y >= c) continue;
      if (dist2[x][y] >= 0 || board[x][y] == '#') continue;
      // 방문한 곳 || #일때

      dist2[x][y] = dist2[curr.X][curr.Y] + 1;
      Q2.push({x, y});
    }
  }

  // 지훈이 위치
  while (!Q1.empty()) {
    curr = Q1.front();
    Q1.pop();

    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      if (x < 0 || y < 0 || x >= r || y >= c) {
        // 이탈시 탈출 성공이다.
        // 탈출까지의 시간  == 현재까지의 거리
        cout << dist1[curr.X][curr.Y] + 1;
        return 0;
      }

      if (dist1[x][y] >= 0 || board[x][y] == '#') continue;
      // 방문한 곳 || #일때

      // 불이 지나갔다 && 해당 좌표에 왔을시의 불의 시간 <= 지훈이가 해당 위치
      // 왔을 시의 시간
      if (dist2[x][y] != -1 && dist2[x][y] <= dist1[curr.X][curr.Y] + 1)
        continue;

      dist1[x][y] = dist1[curr.X][curr.Y] + 1;
      Q1.push({x, y});
    }
  }

  // 도달시 탈출 할 수 없음
  cout << "IMPOSSIBLE";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}
