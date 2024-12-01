#include <iostream>
#include <vector>
using namespace std;
#define MAX 26

vector<char> v[MAX];
int checked[MAX];
/**
 * 트리 순회
 * 없을때는 . 의 값을 주니까 완전 이진트리
 */

void prevSearch(int parentNodeIdx) {
  if (parentNodeIdx < 0) {
    return;
  }

  char mid = 'A' + parentNodeIdx;
  cout << mid;
  prevSearch(v[parentNodeIdx][0] - 'A');
  prevSearch(v[parentNodeIdx][1] - 'A');
}

void midSearch(int parentNodeIdx) {
  if (parentNodeIdx < 0) {
    return;
  }

  midSearch(v[parentNodeIdx][0] - 'A');
  char mid = 'A' + parentNodeIdx;
  cout << mid;
  midSearch(v[parentNodeIdx][1] - 'A');
}

void endSearch(int parentNodeIdx) {
  if (parentNodeIdx < 0) {
    return;
  }

  endSearch(v[parentNodeIdx][0] - 'A');
  endSearch(v[parentNodeIdx][1] - 'A');
  char mid = 'A' + parentNodeIdx;
  cout << mid;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  fill(checked, checked + MAX, -1);

  char m, left, right;
  while (n--) {
    cin >> m >> left >> right;
    v[m - 'A'].push_back(left);
    v[m - 'A'].push_back(right);
  }

  prevSearch(0);
  cout << '\n';

  midSearch(0);
  cout << '\n';

  endSearch(0);
  cout << '\n';

  return 0;
}