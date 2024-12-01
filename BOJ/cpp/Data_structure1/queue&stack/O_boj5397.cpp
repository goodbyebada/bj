#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 실버 2
 * 키로거 문제
 *
 * -- 문제
 * 1, 커서 앞에 글자가 있다면 - 지운다.
 * 2. 커서 화살표를 통해 이동할 수 있다.
 * 3. 커서의 위치가 줄의 마지막이 아닐때 입력이 들어온다면, 커서및 커서 오른쪽
 * 글자는 오른쪽으로 이동한다.
 *
 * --
 * 1. 커서의 위치를 확인해야한다.
 *
 * 2. vector stack empty일때 < > -를 만나면 무시한다.
 * 3. - 를 만나면 pop()
 * 커서의 위치
 * < 만날때마다 end.push(top()) 하고 pop()
 * 만약 v.empty()라면 아무것도 하지 않는다.
 * > 만날때마다 vector.push_back(end.top()) end.pop()
 * 만약 end.empty()라면 아무것도 하지 않는다
 *
 *
 * --- 틀렸던 이유 찾음
 * 입력을 다 받았다면
 * stack을 마저 다 비운다.
 * 테스트 케이스가 전부가 아니다. 반성하자!
 */

vector<char> checkString(string test) {
  vector<char> ans;
  stack<char> end;
  char c;

  for (int i = 0; i < test.length(); i++) {
    c = test[i];

    switch (c) {
      case '<':
        if (ans.empty()) {
          break;
        }
        end.push(ans.back());
        ans.pop_back();
        break;
      case '>':

        if (end.empty()) {
          break;
        }

        ans.push_back(end.top());
        end.pop();
        break;

      case '-':
        if (ans.empty()) {
          break;
        }
        ans.pop_back();
        break;

      default:
        ans.push_back(c);
        break;
    }
  }

  while (!(end.empty())) {
    ans.push_back(end.top());
    end.pop();
  }

  return ans;
};

int boj() {
  int N;
  vector<string> test;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    test.push_back(input);
  }

  for (int i = 0; i < test.size(); i++) {
    vector<char> result = checkString(test[i]);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i];
    }
    cout << "\n";
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}