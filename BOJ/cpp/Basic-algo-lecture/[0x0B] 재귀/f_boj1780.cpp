#include <iostream>
#define MAX 2200
using namespace std;

/**
 * 종이의 개수
 * 실버 2
 *
 *
 * 1.첫번째 줄부터 탐색한다.
 * 2. 다른 개 있다면 바로 자른다. N/3의 범위에서 탐색한다.
 * 다시 맨 처음부터 탐색한다.
 * 한 네모 필드를 다 돌고 마지막 숫자 cnt++
 *
 * 그 다음으로 넘어간다.
 * (1)과 같이 반복한다.
 */

int arr[MAX][MAX];

int Count[3];

// 다 같다면
bool check(int firstRow, int firstCol, int N) {
  for (int i = firstRow; i < firstRow + N; i++) {
    for (int j = firstCol; j < firstCol + N; j++) {
      if (arr[firstRow][firstCol] != arr[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void solve(int x, int y, int z) {
  if (check(x, y, z)) {
    Count[arr[x][y] + 1] += 1;

    return;
  }

  int n = z / 3;

  //   그 다음 탐색을 위한 로직
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(x + i * n, y + j * n, n);
    }
  }
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  solve(0, 0, N);

  for (int i = 0; i < 3; i++) {
    cout << Count[i] << '\n';
  }

  return 0;
}