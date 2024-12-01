#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 에디터
 * 실버 2
 *
 *
 * 1. L  커서를 왼쪽으로 한 칸 옮김 , 커서가 문장의 맨 앞이면 무시된다.
 * 2. D 커서를 오른쪽으로 한 칸 옮김, 커서가 문장의 맨 뒤이면 무시된다.
 * 3, B 커서 왼쪽에 있는 문자를 삭제한다.  커서의 위치는 그대로이다.
 * 4. P $ , $라는 문자를 커서 왼쪽에 추가한다.
 *
 *
 * - 틀렸던 이유
 * 커서라는 게 헷갈렸다.
 * 커서는 왼쪽에 있어야 하니까, insert후 iterator을 1만큼 줄여 틀렸었다.
 * iterator와 커서가  동일하다 생각하니 금방 디버깅할 수 있었다.
 *
 */

void moveCursor(list<char>* L, list<char>::iterator& t, char command) {
  if (command == 'L') {
    if (L->begin() != t) {
      t--;
    }
  } else if (command == 'D') {
    if (t != L->end()) {
      t++;
    }
  }
}

int boj() {
  list<char> L = {};
  list<char>::iterator t;
  string str;
  int n;
  char command, inputChar;

  cin >> str;

  for (char c : str) {
    L.push_back(c);
  }
  t = L.end();

  cin >> n;

  while (n--) {
    cin >> command;

    if (command == 'L' || command == 'D') {
      moveCursor(&L, t, command);
    } else if (command == 'B') {
      if (t != L.begin()) {
        // t가 가리키는 값 제거,
        //  그 다음 원소의 위치를 반환
        t--;
        t = L.erase(t);
      }

    } else if (command == 'P') {
      //   t가 가리키는 곳 앞에 삽입
      cin >> inputChar;
      L.insert(t, inputChar);
    }
  }

  for (char c : L) {
    cout << c;
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