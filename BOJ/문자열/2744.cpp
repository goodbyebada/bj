#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
브론즈 5
2:28 ~

대문자 소문자 차이 32
대문자 65~90
소문자 97~122

1.배열로 받는다.
2.하나씩 검사한다. 95보다 작으면 +32, 크면 -32
3.char형으로 반환한다.
*/

int boj() {

  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    int num = str[i];
    if (num < 95) {
      str[i] = num + 32;
    } else {
      str[i] = num - 32;
    }
  }

  cout << str;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}