#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 오큰수
 * 골드 4
 *
 *
 * -- 처음 접근 방법
 * 1. 하나씩 순회
 * N-1을 하나씩 순회
 * Ai보다 크고 가장 왼쪽에 있는 수를 찾는다.
 *
 *
 * -- ! 방법이 생각나지 않았다.
 * 최악의 경우
 * O(N^2) => 시간초과
 *
 *
 * -- 설명보고 구현
 * 왼쪽에서 오른쪽으로 훑는다.
 * 오른쪽에 나보다 큰 수가 등장하면 오큰수 확정
 * 오큰수가 확정됐을때는 최근에 나온 애부터 비교를 해야한다.
 * 때문에 스택이 적합하다.
 *
 *-- ! 출력을 어떻게 해야할지 모르겠다.
  처음 배열 순서대로 값을 출력해야하는데 , 스택이 안쌓이고 바로 출력되면
 순서대로고, 스택이 쌓이면 역순으로 출력된다.
=> 값이 아니라 인덱스로 스택에 넣는다.
=> 출력 배열에 넣을때 index 통해서 넣으면 된다
 *
 * -- !cpp
 * 지역변수로 배열선언시 쓰레기값 들어간다. 까먹고 있었다..
 *
 */

int N;
vector<int> arr;
stack<int> s;
int ansArr[1000001];

int boj() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int value;
    cin >> value;
    arr.push_back(value);
  }

  // 비교
  for (int i = 0; i < arr.size(); i++) {
    int nowVal = arr[i];

    while (!s.empty()) {
      if (nowVal > arr[s.top()]) {
        ansArr[s.top()] = nowVal;
        s.pop();
      } else {
        break;
      }
    };

    s.push(i);
  }

  for (int i = 0; i < arr.size(); i++) {
    if (!ansArr[i]) {
      cout << "-1" << " ";
    } else {
      cout << ansArr[i] << " ";
    }
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