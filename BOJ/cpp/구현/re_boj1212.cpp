
#include <iostream>
using namespace std;

/**
 * 오리
 * 실버 2
 *
 * - 메모리 초과로 틀렸던 문제에, 한번도 quack이 들어가지 않았을때 에러 처리를
 * 하니 통과됐다.
 *
 */

#include <queue>
queue<char> q;

int idx;
int duckCount;

char arr[5] = {'q', 'u', 'a', 'c', 'k'};

bool flag = false;

void sol(queue<char> &q) {
  queue<char> newQ;

  flag = false;
  while (!q.empty()) {
    char curr = q.front();
    if (curr == arr[(idx % 5)]) {
      flag = true;
      idx++;
    } else {
      newQ.push(curr);
    }
    q.pop();
  }

  duckCount++;

  //   큐를 비웠는데 idx %5 !=0 -1을 출력한다.
  if (idx % 5 != 0 || !flag) {
    cout << -1;
    return;
  }

  if (newQ.empty()) {
    cout << duckCount;
    return;
  }

  sol(newQ);
}

int main() {
  string s;
  queue<char> newQ;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    q.push(s[i]);
  }

  sol(q);

  return 0;
}