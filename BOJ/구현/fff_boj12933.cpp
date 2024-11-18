

#include <iostream>
using namespace std;

/**
 * 오리
 * 실버 2
 * 31
 *
 * 오리의 최소 개수를 구하여라
 * 1. q u a c k 순서대로 소리가 나야한다.
 * 2. 올바르지 않은 입력이면 -1을 출력한다.
 * 3. 문자열을 앞부터 순회한다.
 * 해당한다면 순서대로 찾는다.
 * q u a가 아니라면 다음 인덱스
 * 연속으로 내도 오리 소리이다.
 *
 */

#include <queue>
queue<char> q;

int idx;
int duckCount;

char arr[5] = {'q', 'u', 'a', 'c', 'k'};

/**
 * 큐 순회할때 arr[ ]
 * i++ %5
 * 일치한다면 pop i++
 * 일치하지 않는다면 새로운 큐에 넣는다.
 * 큐가 비면 종료한다.
 */

bool valid = false;

void searchOnce() {
  queue<char> newQ;
  valid = false;

  while (!q.empty()) {
    char curr = q.front();
    if (curr == arr[(idx % 5)]) {
      idx++;
      valid = true;
    } else {
      newQ.push(curr);
    }
    q.pop();
  }

  q = newQ;
  return;
}

int main() {
  string s;
  queue<char> newQ;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    q.push(s[i]);
  }

  while (!q.empty()) {
    searchOnce();

    //   큐를 비웠는데 idx %5 !=0 -1을 출력한다.
    if (idx % 5 != 0 || valid == false) {
      cout << -1;
      return 0;
    }

    duckCount++;
  }

  cout << duckCount;

  return 0;
}