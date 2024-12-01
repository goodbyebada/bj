#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 골드 4
 * 스카이라인 쉬운거
 * 스카이라인의 고도가 바뀌는 지점 x와 y가 주어진다.
 *
 * --- bruteforce
 * 1.y좌표를 통해서 높이를 몇 층 건물인지 판단한다.
 * 2.만약 y좌표가 0이 나온다면, 배열에 들어있는 N층 건물이 나와도 되어도
 * 상관없다.
 * 배열에 넣는다.
 * min max 사이에 있다면 무조건 cnt++하니까 맞지 않다.
 *
 * --- ! 답지 봄
 * y 좌표가 이전보다 작아질때마다 건물 개수를 세어준다.
 * 도저히 모르겠읍니다.
 * 1. 건물의 y 좌표들을 순서대로 push 해줄 stack을 만든다
 * 2. 스택이 비어있지 않고 s.top() > y 건물개수를 증가시킨다. 그리고 pop을 한다.
 * top과 y가 같다면 pop 한다.
 * 3. 스택에 현재 y값을 push한다.
 *
 * ?? 뭔소리고
 *
 * stack
 *
 */

int boj() {
  int N;
  cin >> N;

  stack<int> s;
  int cnt = 0;

  while (N--) {
    int x, y;
    cin >> x >> y;

    // 0일때
    if (y == 0) {
      while (!s.empty()) {
        s.pop();
      }
      continue;
    }

    // 처음일때
    if (s.empty()) {
      s.push(y);
      cnt++;
      continue;
    }

    // 이전 높이가 더 작을때
    if (!s.empty() && s.top() < y) {
      s.push(y);
      cnt++;
      continue;
    } else {
      // 이전 높이가 더 클때
      while (!s.empty() && s.top() > y) {
        s.pop();
      }
      // 남은 블록의 높이가 같을때
      if (!s.empty() && s.top() == y) {
      } else {
        s.push(y);
        cnt++;
      }
    }
  }

  cout << cnt;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}