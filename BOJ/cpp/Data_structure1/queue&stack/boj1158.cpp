#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define endl '\n';

/**
 *
 * 1H 23M
 *
 *index ++ 떄문에 다음 index를 가리키면서 끝내는데 그것을 못잡아 헤맨듯하다.


 * 1 2 3 4 5 6 7
 * 1. 배열을 3개  만든다.
 * 2. 제거 당한 사람을 넣을 배열,
 * 그리고 계속 회전을 할 배열,
 * 제거 당한 여부를 체크할 수 있는 배열을 만든다
 *
 *
 * index 접근 %N으로 해야함
 * 3. arr 배열에 1~N개의 입력 값을 넣는다.
 * 4. arr vetor에서 현재 index보다 3만큼 더 가 제거한다.
 * +3만큼 가는 길에 있는 index에 모든 값이 checked에서 false임을 체크해야한다.
 * 제거한 값은 answer 큐에 넣는다.
 * checked[제거당한 숫자] = true 체크를 한다.
 *
 *
 * (N-2)* 3 * N O(N^2)
 * 하지만 2초라서 그냥 했다
 *
 * 0번 인덱스 +1의 value가 있다는 것 헷갈리지 말것
 * index는 val - 1
 *
 *
 * 제거한 값을 빼고 하나씩 땡기는 방법을 몰랐는데 그냥 배열의 값을 다시 넣어주면
 되는거였다..
 *
 */
int boj() {
  vector<int> ans;
  bool checked[10001] = {false};
  vector<int> numbers;

  int N, K;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    numbers.push_back(i + 1);
  }

  //   체크

  int index = 0;

  // aswer의 길이가 N일때까지 반복한다.
  while (ans.size() != N) {
    int cnt = 0;

    while (cnt < K) {
      if (checked[index % N]) {
        index++;
        continue;
      }

      if (!checked[index % N]) {
        index++;
        cnt++;
      }
    }

    int realIDX = (index + N - 1) % N;

    checked[realIDX] = true;
    ans.push_back(numbers[realIDX]);
    index = realIDX;
  }

  //   //   출력

  cout << "<";

  for (int i = 0; i < ans.size(); i++) {
    if (i == ans.size() - 1) {
      cout << ans[i];
      break;
    }
    cout << ans[i] << ", ";
  }

  cout << ">";

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  boj();
  return 0;
}