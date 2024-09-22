#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * boj1251
 * 단어나누기 문제 실버 5
 *
 * 실패 사유:
 * 문제 푸는데 30분 이상 걸림
 * ?? : 문제다. 그럼 0번이랑 1번 index 뒤에 있는 놈을 pop하려면 무슨 자료구조를
 사용해야할지 모르겠음 막혔다.
 *
 * 문제 해결 방법:
    1. 0 ~ N-3까지 순회한다.
    2. 0번째 인덱스를 큐에 넣는다.
    3. 인덱스를 증가시킨다.
    4. 큐의 0번째 인덱스와 비교한다.
    5. 현재 알파벳[i]가 queue.front 보다 크다면, pop 시키고 현재 알파벳을
 넣는다.
    6. 반복한다.
    만약, 같은 단어라면 이전의 index끼리 비교한다.
    ?? : 문제다. 그럼 0번이랑 1번 index 뒤에 있는 놈을 pop시키려면 우째야함?

    순회가 끝난다면 각각의 인덱스에서 ~ 거꾸로 간다. 하나씩 비교해 더 큰
 인덱스를 기억해둔다. 이 과정을 middle도 반복한다. 마지막 3은 자동으로 정해진다
 index를 기억해둬서  순회하는 방식으로 한 후 return 하면 된다. O(N^2)으로
 예상한다.
 *
 */

#include <algorithm>  // reverse 함수 사용
#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  cin >> word;

  int n = word.size();
  string smallest_word = "~";
  // '~'는 사전적으로 가장 뒤에 있는 문자

  // 첫 번째 자를 위치 i (첫 번째 부분이 끝나는 위치)
  for (int i = 1; i < n - 1; ++i) {
    // 두 번째 자를 위치 j (두 번째 부분이 끝나는 위치)
    for (int j = i + 1; j < n; ++j) {
      // 각 부분을 나누고 뒤집기
      string part1 = word.substr(0, i);
      string part2 = word.substr(i, j - i);

      // 끝에 있는 글자
      string part3 = word.substr(j);

      reverse(part1.begin(), part1.end());
      reverse(part2.begin(), part2.end());
      reverse(part3.begin(), part3.end());

      // 세 부분을 합치기
      string new_word = part1 + part2 + part3;

      // 사전 순으로 가장 앞서는 단어를 찾기
      if (new_word < smallest_word) {
        smallest_word = new_word;
      }
    }
  }

  // 결과 출력
  cout << smallest_word << endl;

  return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char X[51], res[51], s[51];

// 1등 답안
int function() {
  scanf("%s", X);
  int len = strlen(X);

  //   len이 50이라면 48번
  for (int i = 1; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      strcpy(s, X);
      //   s에 X를 복사
      reverse(s, s + i), reverse(s + i, s + j), reverse(s + j, s + len);
      if (!res[0] || strcmp(s, res) < 0) strcpy(res, s);
    }
  }
  printf("%s", res);
}