

#include <iostream>
using namespace std;
using ll = long long;

/**
 * 곱셈
 * 실버 1
 *
 * 수가 매우 커질 수 있기 때문에 mod를 사용한다.
 * (a*a) 를 B번 반복
 * C로 나눈 나머지
 *
 * ->b가 최대 21억이기 때문에 시간 초과
 *
 * a^n*a^n = a^(2*n)과 동일함을 이용해야한다.
 */

ll moduler(ll a, ll b, ll c) {
  // baseCondition
  if (b == 1) return a % c;

  //  a^n*a^n = a^(2*n)과 동일함을 이용해야한다.
  ll val = moduler(a, b / 2, c);
  val = val * val % c;

  if (b % 2 == 0) return val;
  return val * a % c;
  // 홀수일 경우 한번 더 a를 곱해준 후 나눈다.
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << moduler(a, b, c);

  return 0;
}