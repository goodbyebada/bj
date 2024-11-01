#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 1001
#include <algorithm>

using namespace std;

vector<int> graph[MAX];
stack<int> S;
queue<int> Q;

/**
 * 정점 번호는 1번부터 N
 *
 * DFS/BFS 탐색 결과
 * 정점 번호가 작은 순으로
 */

int dfs(int startIdx, bool *visit) {
  S.push(startIdx);

  while (!S.empty()) {
    int curr = S.top();
    S.pop();

    // 이미 방문한 노드일 수 있다.
    // pop할때 확인해야한다.
    // BFS와 다름
    if (visit[curr]) continue;

    visit[curr] = true;
    cout << curr << " ";

    for (int i = 0; i < static_cast<int>(graph[curr].size()); i++) {
      // 스택 특성상 역으로 push해야함
      // 작은 것부터 탐색해야하기 때문이다.
      int nx = graph[curr][graph[curr].size() - 1 - i];

      if (visit[nx]) continue;
      S.push(nx);
    }
  }

  return 0;
}

int bfs(int startIdx, bool *visit) {
  Q.push(startIdx);
  visit[startIdx] = true;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    cout << curr << " ";

    for (int i : graph[curr]) {
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

  bool visit[MAX] = {};

  int n, m, v;

  int a, b;

  cin >> n >> m >> v;

  while (m--) {
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  //   작은 정점부터 방문위해 sort
  //   오름차순
  // 정점번호가 1부터 N번까지이다.
  for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

  dfs(v, visit);

  //   visit 초기화
  fill(visit, visit + MAX, 0);

  cout << '\n';

  bfs(v, visit);

  return 0;
}