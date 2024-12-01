
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define X first
#define Y second
using namespace std;

/**
 * 토마토
 * 골드 5
 *
 *
 * 보관 후 하루가 지나면, 익은 토마토들의 인접한 도마도들이 익는다.
 *
 * 상자의 크기 M(가로 칸) N(세로 칸)
 * 정수 1 : 익은 토마토
 * -1 : 토마토가 들어있지 않은 칸
 *
 * 저장부터 모든 토마토가 익어있다면 0 출력
 * 모두 익지 못하는 상황 : -1 출력
 *
 *
 * ** 풀이
 * 최소의 일수 BFS
 *
 *1. 1이 있는 좌표를 찾는다.
  2. 익은 토마토가 있는 위치부터 큐에 넣는다. 방문했음을 표시한다.
  3. pop()하고 상하좌우의 방향을 살핀다. 큐에 넣는다. 방문했음 표시한다.
  큐가 빌 때까지 반복한다.
  4. 현재 위치가 0이고, 상하좌우가 1이라면 큐에 넣는다.
  5. 현재 위치가 1이고, 상하좌우가 0이라면 큐에 넣는다.
  6. pop한 좌표의 x+y가 이전 pop한 좌표의 x+y와 값이 다르다면 day++ 를 해야한다.
  ** 예외 케이스
  예제 3번 케이스...때문에 2개 나눠서 하는게 좋을 듯하다.
 *
 */

/**
 * 틀린 이유
 * 모든 시작점을 찾아 BFS를 돌려고 했다. -> 시간 초과
 * 줄여보고자 반을 나눠서 해결하고자 했는데 그래도 O(NM * NM) 이다.
 *
 *
 * 알게 된 것
 * 시작점을 큐에 다 넣고 BFS를 해도 상관없다.
 * dist 배열만으로  접근 여부를 알 수 있다.
 * 거리를 구하고 싶다면 dist 배열을 이용해 이전 배열 + 1 로 업데이트가 가능하다.
 */

int box[10001][10001];
int vis[10001][10001];

// pair<int, int> curr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int day = 0;
int n, m;

int prevSum, currSum;

pair<int, int> findFirstRedTomato(pair<int, int> S, pair<int, int> E) {
  for (int i = S.X; i < E.X; i++) {
    for (int j = S.Y; j < E.Y; j++) {
      if (box[i][j] == 1) return {i, j};
    }
  }
}

int checkBox(queue<pair<int, int> > &q, pair<int, int> S, pair<int, int> E) {
  pair<int, int> firstRedTomato = findFirstRedTomato(S, E);

  q.push(firstRedTomato);
  vis[firstRedTomato.X][firstRedTomato.Y] = 1;

  if (!q.empty()) {
    pair<int, int> curr = q.front();
    prevSum = curr.X + curr.Y;
  }

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    currSum = curr.X + curr.Y;

    if (prevSum != currSum) {
      prevSum = currSum;
      day++;
    }

    q.pop();

    // 한 좌표에 대한 검사
    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      if (x < S.X || y < S.X || y >= E.Y || x >= E.X) continue;

      if (box[x][y] == -1 || vis[x][y] == 1) continue;

      if ((box[curr.X][curr.Y] == 1 && box[x][y] == 0) ||
          (box[curr.X][curr.Y] == 0 && box[x][y] == 1)) {
        box[x][y] = 1;

        q.push({x, y});
      };
      vis[x][y] = 1;
    }
  }
}

int isAllRedTomato() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (box[i][j] == 0) return false;
    }
  }

  return true;
}

int boj() {
  queue<pair<int, int> > q;

  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];
    }
  }

  if (isAllRedTomato()) return 0;
  checkBox(q, {n / 2, m / 2}, {n, m});
  checkBox(q, {0, 0}, {n / 2 + 1, m / 2 + 1});

  cout << day;

  if (isAllRedTomato()) {
    return day;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << boj();
  return 0;
}