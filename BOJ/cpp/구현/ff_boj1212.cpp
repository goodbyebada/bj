
#include <iostream>
#include <string>
using namespace std;

int main() {
  string octal;
  cin >> octal;

  if (octal == "0") cout << 0 << '\n';

  string result;
  for (int i = 0; i < octal.length(); i++) {
    // octal[i]를 십진수로 보고 2진수로 바꿔준다.
    // 3자리수만 필요하기 때문에

    // char이기 때문에 '0'을 해줘야한다.
    // 0 ~ 9일때만 유효하다.
    // ex) '11' - '0' X
    result += to_string((octal[i] - '0') / 4);
    // 2^2 자리에 오는 값
    result += to_string(((octal[i] - '0') % 4) / 2);
    // 2^1자리에 오는 값
    result += to_string((((octal[i] - '0') % 4) % 2) / 1);
    // 2^0 자리에 오는 값
  }

  bool flag = false;
  for (int i = 0; i < result.length(); i++) {
    if (!flag) {
      if (result[i] == '1') {
        flag = true;
        cout << result[i];
      }
    } else {
      cout << result[i];
    }
  }
  cout << '\n';

  return 0;
}