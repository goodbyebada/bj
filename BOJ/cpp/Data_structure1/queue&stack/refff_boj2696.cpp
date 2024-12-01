#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 골드 2
 * ** 출력초과

 * O(N!)
 * 1초가 넘는지는 모르겠다.
 * 어느정도 정렬되어있으니까 덜 돌지 않을까?
 * 다 꺼내도 O(N) 넣고 빼는데 O(1)
 *
 * O(N)* N번수행
 * O(N^2)
 * 1초 안됨
 
 * 다 정렬하고 홀수 번째일때 top을 출력한다.
 *
 *
 * ---
 * index가 짝수라면
 * 현재 index+1/2
 * stack의 사이즈가 될때  top()을 정답outPutArr push한다.
 *
 */

vector<int> outPutArr;

int outPut() {
  cout << outPutArr.size() << '\n';

  for (int i = 1; i <= outPutArr.size(); i++) {
    if ((i) % 10 == 0) {
      cout << outPutArr[i - 1] << '\n';
    } else {
      cout << outPutArr[i - 1] << " ";
    }
  }
  return 0;
}

int check(int input, vector<int> &s, int index) {
  stack<int> tmp;

  // 첫번째 input
  if (s.empty()) {
    s.push_back(input);

    if (index == 0) {
      outPutArr.push_back(s.back());
    }
    return 0;
  }

  // 비워져있지않을때
  while (!s.empty() && s.back() > input) {
    tmp.push(s.back());
    s.pop_back();
  }
  // s.back() <= tmp
  s.push_back(input);

  while (!tmp.empty()) {
    s.push_back(tmp.top());
    tmp.pop();
  }

  // 짝수일때
  if (index % 2 == 0) {
    outPutArr.push_back(s[(index / 2)]);
  }

  return 0;
}

int boj() {
  int N, len, elem;
  cin >> N;
  while (N--) {
    outPutArr.clear();
    cin >> len;
    vector<int> s;
    for (int i = 0; i < len; i++) {
      cin >> elem;
      check(elem, s, i);
    }
    outPut();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}