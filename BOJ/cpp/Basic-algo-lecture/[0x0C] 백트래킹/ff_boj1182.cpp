#include <iostream>
using namespace std;
#define MAX 20

/**
 * 부분수열의 합
 * 실버 2
 */

int arr[MAX];
int n, s;
int cnt = 0;

void func(int curr, int tot) {
  // baseCondition

  if (curr == n) {
    if (tot == s) {
      cnt++;
    }

    return;
  }

  func(curr + 1, tot);
  // 자리수가 늘어난다. 깊이가 한 단계 깊어진다.
  // arr[curr]가 있을때 없을때의 경우로 나눈다.

  func(curr + 1, tot + arr[curr]);
}

int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  func(0, 0);

  if (s == 0) cnt--;
  // s가 0이라면 공집합도 세어졌기 때문에 제거해야한다.
  cout << cnt;

  return 0;
}