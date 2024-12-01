#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 두 수의 합
 * 실버 3
 */

// 전역에서 되는 초기화
int n, x;
int arr[1000001] = {};
bool curr[2000001];
int pairCnt;

int boj() {
  // 수열의 크기
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cin >> x;

  for (int i = 0; i < n; i++) {
    // 짝인 수가 양수여야함 && 현재 배열에 존재해야함
    if ((x - arr[i]) > 0 && curr[x - arr[i]]) {
      pairCnt++;
    }

    // 둘 중 하나만 있어도 pairCnt가 처리된다.
    curr[arr[i]] = true;
  }

  cout << pairCnt;

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}