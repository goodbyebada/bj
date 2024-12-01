#include <iostream>
using namespace std;

/**
 * 원상 복구(small)
 * 실버 3
 *
 * 32M
 */

/**
 * s의 값을 직접 바꾼다.
 * 내부에서 s의 원본을 카피한 후, s에 셔플한 결과를 넣는다.
 */
void backToShuffle(int *s, int *d, int n) {
  int p[n];

  for (int i = 0; i < n; i++) {
    p[i] = s[i];
  }

  for (int i = 0; i < n; i++) {
    s[d[i] - 1] = p[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int s[n];
  int d[n];

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i < k; i++) {
    // p를 마지막에 변경하는걸로
    backToShuffle(s, d, n);
  }

  // read-only
  // 직접 참조
  for (const int &i : s) {
    cout << i << " ";
  }
  cout << '\n';

  return 0;
}