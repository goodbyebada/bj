#include <iostream>
#include <queue>
using namespace std;

/**
 * 숨바꼭질
 * 실버 1
 *
 *
 ** 문제 요약
 * 수빈이는 걷거나 순간이동이 가능하다.
 * 수빈이가 걸으면 X-1,X+1
 * 순간이동 시에는 X*2
 *
 * 수빈이가 동생을 찾는 가장 빠른 시간은?
 *
 *
 */

int dist[100002];
queue<int> Q;

int boj() {
  // 수빈이의 위치, 동생의 위치
  int N, M, curr;
  cin >> N >> M;

  fill(dist, dist + 100001, -1);

  Q.push(N);
  dist[N] = 0;

  while (dist[M] == -1) {
    curr = Q.front();
    Q.pop();

    for (int k : {curr - 1, curr + 1, curr * 2}) {
      if (k < 0 || k > 100000) continue;
      if (dist[k] != -1) continue;

      dist[k] = dist[curr] + 1;
      Q.push(k);
    }
  }

  cout << dist[M];

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  boj();

  return 0;
}