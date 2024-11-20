#include <iostream>
using namespace std;
/**
 * 달팽이
 * 실버 3
 *
 * 다른 분의 코드르 보고 공부하였다.
 * (0,0)에서 접근하는 방식이다.
 */

int a[1001][1001];  // 최대 1000x1000 크기의 배열
int n, m;           // n: 배열 크기, m: 찾고자 하는 숫자
int dir = 0;        // 현재 이동 방향
int rety, retx;     // m의 위치를 저장할 변수
int y = 0, x = 0;   // 현재 위치 (시작점은 (0, 0))

const int dy[] = {1, 0, -1, 0};  // 아래, 오른쪽, 위, 왼쪽 순
const int dx[] = {0, 1, 0, -1};

int main() {
  cin >> n >> m;

  // n x n 배열을 나선형으로 숫자 채우기
  for (int i = n * n; i > 0; i--) {  // i는 현재 채울 숫자 (n*n부터 시작)
    a[y][x] = i;                     // 현재 위치에 숫자 채우기
    if (i == m) {    // m과 같은 숫자를 찾으면 위치 저장
      rety = y + 1;  // 배열은 1-indexed로 출력해야 하므로 +1
      retx = x + 1;
    }

    // 다음 위치 계산: 범위를 벗어나거나 이미 채워진 경우 방향 전환
    if (y + dy[dir] < 0 || y + dy[dir] >= n ||  // y가 배열 범위를 벗어나거나
        x + dx[dir] < 0 || x + dx[dir] >= n ||  // x가 배열 범위를 벗어나거나
        a[y + dy[dir]][x + dx[dir]] != 0) {
      dir = (dir + 1) % 4;
    }

    // 현재 위치를 다음 위치로 이동
    y = y + dy[dir];
    x = x + dx[dir];
  }

  // 배열 출력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }

  // m의 위치 출력 (1-indexed)
  cout << rety << " " << retx << "\n";

  return 0;  // 프로그램 종료
}
