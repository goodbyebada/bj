#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace std;

/**
 * 그래프의 연결 요소 개수를 구해라
 *
 * !! 연결 요소 개수이다.
 * 간선의 길이를 말하는 것이 아니다..
 *
 * 잔 실수가 많다.
 *
 * 1. 방문 여부 확인
 * 2. 문제 이해 -> 테케를 유심히 보자
 */

vector<int> graph[MAX];
bool visit[MAX];
queue<int> Q;
int cnt;

int BFS(int i) {
  Q.push(i);
  visit[i] = true;
  cnt++;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    for (auto i : graph[curr]) {
      if (visit[i]) continue;

      Q.push(i);
      visit[i] = true;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;

  cin >> n >> m;

  int u, v;
  while (m--) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    // !! 방문했는지 검사
    if (visit[i]) continue;
    BFS(i);
  }

  cout << cnt;

  return 0;
}