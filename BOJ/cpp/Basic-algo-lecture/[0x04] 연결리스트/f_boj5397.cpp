#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 키로거
 * 실버 2
 *
 * - 커서 앞글자에 글자가 있다면 지운다
 * < 커서 왼쪽으로 움직인다.
 * > 오른쪽으로 움직인다.
 * 커서는 오른쪽에 있어야한다.
 *
 */
int boj() {
  int n;
  string str;

  cin >> n;
  while (n--) {
    cin >> str;

    list<char> L;
    auto it = L.begin();

    for (auto c : str) {
      if (c == '<') {
        if (it != L.begin()) it--;

      } else if (c == '>') {
        if (it != L.end()) it++;

      } else if (c == '-') {
        // 헤맸던 곳
        if (it != L.begin()) {
          it--;
          it = L.erase(it);
        }
      } else {
        L.insert(it, c);
      }
    }

    for (auto c : L) cout << c;
    cout << "\n";
  };

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}