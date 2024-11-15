#include <iostream>
using namespace std;

/**
 * N-Queen
 * 골드 5
 *
 * 퀸은 상하좌우 대각선을 공격한다.
 * 퀸에게 공격을 받지 않는 법
 *
 * 1. 같은 행에 위치하면 안된다.
 * 2. 같은 열에 위치하면 안된다.
 * 3. 대각선상에 위치하면 안된다.

 */

using namespace std;
bool isused1[40];
// 열을  차지하고 있는지
bool isused2[40];
// / 방향 대각선을 차지하고 있는지
bool isused3[40];
// \ 방향 대각선을 차지하고 있는지

int cnt = 0;
int n;
void func(int cur) {
  // cur번째 row에 말을 배치할 예정이다.
  if (cur == n) {
    // N개를 놓는데 성공했다면 카운트 수를 높인다.
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++) {
    // (cur, i)에 퀸을 놓을 예정이다.
    if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1])
      // column이나 대각선 중에 문제가 있을시
      continue;
    isused1[i] = 1;
    isused2[i + cur] = 1;
    isused3[cur - i + n - 1] = 1;
    func(cur + 1);
    isused1[i] = 0;
    isused2[i + cur] = 0;
    isused3[cur - i + n - 1] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}