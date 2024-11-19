#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 완전 이진 트리
 * 실버 1
 *
 * 왼쪽 자식 먼저 방문 (방문하거나 없다면-> 현재 -> 오른쪽 다 방문했다면
 * 부모노드로 이동한다. 식으로 방문을 이미했고 레벨대로 출력해야한다. level은
 * k이다.
 */

int k;
vector<int> v;
vector<int> tree[10];
// 최대 10개 준다고 한다.

void sol(int s, int e, int d) {
  // 마지막 리프 노드
  if (s == e) {
    tree[d].push_back(v[s]);

    // 중앙값이 아니라 s||e 값을 넣는다.
    // 리프노드이니까.
    return;
  }

  int idx = (s + e) / 2;
  tree[d].push_back(v[idx]);

    // 왼쪽 트리 방문
  sol(s, idx - 1, d + 1);
  // 오른쪽 트리 방문
  sol(idx + 1, e, d + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;

  int num = pow(2, k) - 1;
  //   완전 이진 트리 노드 개수

  for (int i = 0; i < num; i++) {
    int number;
    cin >> number;
    v.push_back(number);
  }

  sol(0, num - 1, 0);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < tree[i].size(); j++) {
      cout << tree[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}