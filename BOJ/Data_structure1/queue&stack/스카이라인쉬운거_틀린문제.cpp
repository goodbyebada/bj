#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int boj() {
  int N;
  cin >> N;

  stack<int> s;
  int cnt = 0;

  while (N--) {
    int x, y;
    cin >> x >> y;

    // 처음일때
    if (s.empty()) {
      s.push(y);
      cnt++;
      continue;
    }

    // 0일때
    if (y == 0) {
      while (!s.empty()) {
        s.pop();
      }
      continue;
    }

    int flag = 1;
    while (!s.empty()) {
      // 처음 push할때 count
      if (s.top() < y) {
        s.push(y);
        cnt += flag;
        break;
      } else {
        s.pop();
        flag = 0;
      }
    }
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}