#include <cmath>
#include <deque>
#include <iostream>
using namespace std;
/**
 * 카드섞기
 * 골드 5
 *
 * 1:01~
 *
 *
 * k+1 단계
 *
 * ex) k =2
 * 3단계
 *
 * 1: 밑이 2^k를 더미 맨위로
 * i: 옮긴 더미의  밑의 2^(K-i + 1)를 위로
 *
 *
 * 1단계 밑에서  2^k개의 카드를 더미 맨위로 2^2
 * 2단계 직전에 맨 위로 올린 카드 중 밑에서 2개의 카드 맨위로  2^1
 * 3 2^0 1개를 맨 위로
 *
 * (2,K)를 두 번 섞기한 결과를 보고,
 * 결과를 보고 두 번의 K의 값을 알아내라
 *
 * 입력
 * N : 1~N
 * (2,K) 섞기 후의 카드 더미 위에 있는 카드부터 공백으로 구분해서 주어짐
 *
 * 출력
 * 첫번쨰 K
 * 두번째 K
 *
 *
 * ** 아이디어
 * (2,K) 섞기
 *
 *
 */

/**
 * startIndex~endIndex를 가장 앞으로 나오게 하는 함수
 */
void pullToFront(int* target, int startIndex, int endIndex, int n) {
  int copied[n];
  for (int i = 0; i < n; i++) {
    copied[i] = target[i];
  }
  int realIndex = 0;
  for (int i = startIndex; i <= endIndex; i++) {
    target[realIndex++] = copied[i];
  }
  for (int i = 0; i < startIndex; i++) {
    target[realIndex++] = copied[i];
  }
  for (int i = endIndex + 1; i < n; i++) {
    target[realIndex++] = copied[i];
  }
}

/**
 * (2,k) 셔플 함수
 */
void shuffle(int* arr, int k, int n) {
  int flexCount = n;

  for (int i = 1; i <= k + 1; i++) {
    int powed = pow(2, k - i + 1);
    int endIndex = flexCount - 1;
    int startIndex = endIndex - (powed - 1);

    pullToFront(arr, startIndex, endIndex, n);
    flexCount = powed;
  }
}

bool isValid(int* d, int* origin, int n) {
  for (int i = 0; i < n; i++) {
    if (d[i] != origin[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  double n;
  cin >> n;
  int origin[(int)n];

  for (int i = 0; i < n; i++) {
    cin >> origin[i];
  }

  // k1,k2에 대한 이중 for문

  for (int k1 = 1; k1 < n; k1++) {
    if (pow(2, k1) >= n) {
      continue;
    }
    int arr[(int)n];
    for (int x = 1; x <= n; x++) {
      arr[x - 1] = x;
    }
    shuffle(arr, k1, n);
    for (int k2 = 1; k2 < n; k2++) {
      if (pow(2, k2) >= n) {
        continue;
      }
      int arr2[(int)n];
      for (int x = 0; x < n; x++) {
        arr2[x] = arr[x];
      }
      shuffle(arr2, k2, n);
      if (isValid(arr2, origin, n)) {
        cout << k1 << ' ' << k2;
        return 0;
      }
    }
  }

  return 0;
}