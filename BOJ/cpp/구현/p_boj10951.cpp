#include <iostream>
using namespace std;

/**
 * A+B - 4
 * 브론즈 5
 *
 * 입력이 끝날때까지 받기 문제
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num1, num2;

  // while (!cin.eof()) {
  // 을 사용했었을때 틀렸었다.
  //   EOF는 cin.eof() 로는 마지막 입력 이후 추가로 cin이 되어야 감지가 된다.

  // sol1
  while (true) {
    cin >> num1 >> num2;
    if (cin.eof() == true) break;
    // cin 직후 eof 검사를 통해 while문을 나갈 수 있다.
    cout << num1 + num2 << '\n';
  }

  // sol2
  // 입력이 정상적으로 이루어지지 않으면 스트림 상태가 실패 상태로 이뤄진다.
  //   while (cin >> num1 >> num2) {
  //     cout << num1 + num2 << '\n';
  //   }

  return 0;
}