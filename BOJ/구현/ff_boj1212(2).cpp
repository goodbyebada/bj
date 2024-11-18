#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 8진수를 2진수로 변환하는 함수
void convert(int n, vector<int> &ans) {
  int x = 2;
  while (x >= 0) {
    ans.push_back((n >> x) & 1);
    x--;
  }
}

int main() {
  string s;  // 8진수를 문자열로 입력받음
  cin >> s;

  vector<int> ans;

  // 각 자리수를 2진수로 변환
  for (int i = 0; i < s.length(); i++) {
    int num = s[i] - '0';  // 문자를 숫자로 변환
    convert(num, ans);
  }

  // 선행 0을 제거
  bool leading_zero = true;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 1) leading_zero = false;
    // 1이 나오면 선행 0이 끝남
    if (!leading_zero) cout << ans[i];
    // 출력
  }

  // 입력이 "0"일 경우 예외 처리
  if (leading_zero) cout << "0";

  return 0;
}
