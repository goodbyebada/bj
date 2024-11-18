// 아래 틀린 코드

#include <iostream>
using namespace std;
#include <vector>

/**
 * 8진수가 주어졌을때 2진수로 변환한다.
 *
 * 1 ~ 7 10(8)
 * 자리수가 1
 *
 * 8진수 -> 2진수
 * 각 자리수를
 * 3 1 4
 * 011 001  100
 * 1. 받은 각 자리수를 하나씩 2진수로 반환해 출력한다.
 * 2. 0일때를 제외하고 반드시 1로 시작해야한다.
 *
 */

int n, stat;
string s;

vector<int> ans;

int convert(int n) {
  int x = 2;
  while (x >= 0) {
    ans.push_back((n >> x) & 1);
    x--;
  }
  return 0;
}

int main() {
  cin >> s;

  if (s.length() == 1 && s[0] == '0') {
    cout << "0";
    return 0;
  }

  int stat = 0;
  for (int i = 0; i < s.length(); i++) {
    // char
    int num = s[i] - '0';
    convert(num);
  }

  //   bool leading_zero = false;
  //   for (int i = 0; i < ans.size(); i++) {
  //     if (ans[i] == 1) leading_zero = true;
  //     if (leading_zero) cout << ans[i];
  //   }

  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 1) {
      stat = i;
      break;
    }
  }

  for (int i = stat; i < ans.size(); i++) {
    cout << ans[i];
  }

  return 0;
}
