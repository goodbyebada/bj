#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 실버 5
 * 카드 1
 *
 * 짝수일때는 위에 있는 카드를 버린다.
 * 홀수 일때는 카드를 맨 뒤로 넣는다.
 *
 */
int boj() {
  queue<int> q;
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    q.push(i + 1);
  }
  int i = 0;
  while (q.size() != 1) {
    if (i % 2 == 0) {
      cout << q.front() << " ";
      q.pop();
    } else {
      q.push(q.front());
      q.pop();
    }
    i++;
  }

  cout << q.front();
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}