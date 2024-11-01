// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/888234c79cf844af82b67a3c9518b1dd
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<int> adj[1005] = {};
  bool vis[1005] = {};

  ios::sync_with_stdio(0);
  cin.tie(0);

  //   정점의 개수 n, 간선의 개수 m
  int n, m;

  // 그래프 입력 처리

  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;

    //   간선의 양 끝점 u와 v
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // BFS
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    num++;
    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      //   연결되어있는 정점 방문
      for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << num;
}