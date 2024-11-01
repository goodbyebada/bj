#include <iostream>
#define MAX 502
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/**
 * 결혼식
 * 실버 2
 *
 * 동기의 수 N
 * 상근이 1
 *
 * 상근의 친구
 * 상근의 친구의 친구까지 가능
 *
 * 거리가 2까지만 가능하다.
 * BFS를 돌린다. 근데 이제 거리가 2일때까지만 가능한
 *
 * 정점 1에서 출발한다.
 * 1. 큐에 넣는다.
 * 2. 방문 체크를 한다.
 *
 * while()
 * 1. curr 좌표를 남겨두고 pop한다.
 * 3. graph[curr]에 있는 방문하지 않은 인접 리스트를 큐에 넣는다.
 * 4. 큐에 넣을때마다 카운트를 업데이트 한다.
 * 4. 방문 체크를 한다.
 * 5.반복한다.
 * 6. dist 배열을 만들어 업데이트한다. 이때 2가 되는 순간 멈춘다.
 *
 * dist 배열을 이용해 방문여부를 판단한다.
 * 1. dist 배열 전부 -1로 초기화
 * 2. 첫 방문 = 0으로 초기화
 * 3. -1일때만 방문이 가능하다.
 *
 */

vector<int> graph[MAX];
queue<int> Q;
int cnt;
int dist[MAX];

void BFS(int i) {
  Q.push(i);
  dist[i] = 0;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    // 친구의 친구 2이상일때는 방문해야할 노드를 탐색하지 않는다.
    if (dist[curr] >= 2) continue;

    for (auto nxt : graph[curr]) {
      if (dist[nxt] >= 0) continue;

      //   방문
      dist[nxt] = dist[curr] + 1;
      Q.push(nxt);
      cnt++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  int a, b;

  cin >> n >> m;

  fill(dist, dist + MAX, -1);

  while (m--) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  BFS(1);

  cout << cnt;

  return 0;
}