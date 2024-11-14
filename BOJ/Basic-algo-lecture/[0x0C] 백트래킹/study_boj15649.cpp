#include <iostream>
using namespace std;
#define MAX 10001

/**
 * 실버 3
 *
 * N과 M
 * 1부터 N까지 자연수 중에 중복없이 M개를 고른 수열
 *
 * 백트래킹
 */

int n, m;
int arr[MAX];
bool isUsed[MAX];

void backTracking(int k) {
  // k가 m이라면 m개를 골랐다고 할 수 있다.

  //   basecondition
  if (k == m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }

    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!isUsed[i]) {
      // k번째 자리일시
      arr[k] = i;

      //   사용됐음 확인
      isUsed[i] = true;

      //   다음 자리
      backTracking(k + 1);

      // k번째 index가 i 인 m개인 수열을 모두 확인했기 때문에 초기환
      isUsed[i] = false;
    }
  }
}

int main() {
  cin >> n >> m;

  backTracking(0);

  return 0;
}