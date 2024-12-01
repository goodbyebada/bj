#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;

/**
 * Z
 * 실버 1
 */

pair<int, int> pos[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int recursive(int N, int r, int c) {
  if (N == 0) return 0;

  for (int i = 0; i < 4; i++) {
    int x = 2 * (N - 1) + pos[i].X;
    int y = 2 * (N - 1) + pos[i].Y;

    cout << "( " << x << y << ")";

    if (x == r && y == c) cout << (x + y);
  }

  recursive(N / 2, r, c);

  return 0;
}
// Z 모양 순서 계산 함수
// n: 현재 2^n x 2^n 행렬 크기의 단계
// r: 목표 위치의 행 (row)
// c: 목표 위치의 열 (column)
int func(int n, int r, int c) {
  // 기저 사례: n이 0일 경우, 시작 위치(0,0)이므로 0을 반환
  if (n == 0) return 0;

  int half = 1 << (n - 1);
  // 현재 행렬을 반으로 나눈 크기

  // 1번 사분면: r < half, c < half일 때
  if (r < half && c < half) return func(n - 1, r, c);

  // 2번 사분면: r < half, c >= half일 때
  if (r < half && c >= half) return half * half + func(n - 1, r, c - half);

  // 3번 사분면: r >= half, c < half일 때
  if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);

  // 4번 사분면: r >= half, c >= half일 때
  return 3 * half * half + func(n - 1, r - half, c - half);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, c;
  // 사용자 입력을 받아 n, r, c 값 설정
  cin >> n >> r >> c;

  // 주어진 n, r, c 위치에 해당하는 Z 순서 출력
  cout << func(n, r, c);
  return 0;
}