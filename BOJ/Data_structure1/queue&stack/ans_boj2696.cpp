#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> outPutArr;

// 우선순위 큐를 이용한 중앙값 구하기
void check(int input, priority_queue<int> &low,
           priority_queue<int, vector<int>, greater<int>> &high, int index) {
  // 최대 힙에 먼저 넣는다
  if (low.empty() || input <= low.top()) {
    low.push(input);
  } else {
    high.push(input);
  }

  // 두 힙의 크기 차이가 2 이상 나지 않도록 조정
  //   중앙값 기준으로 비교하기 위해 필요하다.
  if (low.size() > high.size() + 1) {
    high.push(low.top());
    low.pop();
  } else if (high.size() > low.size()) {
    low.push(high.top());
    high.pop();
  }

  // 홀수 번째 수일 때만 중앙값을 저장
  if (index % 2 == 0) {
    outPutArr.push_back(low.top());
  }
}

// 출력 함수: 한 번에 출력하도록 개선

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

void boj() {
  int T, len, elem;
  cin >> T;

  while (T--) {
    outPutArr.clear();
    cin >> len;

    priority_queue<int> low;                              // 최대 힙
    priority_queue<int, vector<int>, greater<int>> high;  // 최소 힙

    for (int i = 0; i < len; i++) {
      cin >> elem;
      check(elem, low, high, i);
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
