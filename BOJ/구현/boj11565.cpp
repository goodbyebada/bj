#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define endl '\n'

// 09: 34 ~ 10:12
/**
 *
 * 1. index를 하나씩 밀어가며 for문을 돌아 해당 접미사 문자열들을 만든다.
 * 2. 문자열들의 배열을 하나 만들고 문자열들 맨 앞 알파벳의 순서대로 정렬한다.
 * 3. 다음으로 출력한다.
 *
 * O(n^2)으로 1초는 넘지 않을 것으로 판단된다.
 */
void boj() {
  string word;
  vector<string> words;

  cin >> word;

  int len = word.length();
  for (int i = 0; i < len; i++) {
    string subs_str = word.substr(i, len);
    words.push_back(subs_str);
  }

  sort(words.begin(), words.end());

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}