#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 제로
 * 실버 4
 *
 *
 * 1. 스택을 만든다
 * 2. 0의 값이 들어올때마다 pop한다.
 * 3. 입력값 n번을 반복한다.
 * 4. 스택을 top의 누적값을 반환한다.
 */
int boj() {
  int n;
  int ans = 0;
  stack<int> s;
  cin >> n;

  while (n--) {
    int input;
    cin >> input;

    if (input == 0) {
      s.pop();
    } else {
      s.push(input);
    }
  }

  // 계속된 pop으로 s.size()는 변화한다.
  // 때문에 for문이 아닌 empty()
  while (!s.empty()) {
    ans += s.top();
    s.pop();
  }

  cout << ans;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}