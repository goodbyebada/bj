#include <iostream>
#include <sstream>
#include <vector>
#define endl '\n'

using namespace std;

/**
 * 이진 검색 트리
 * 골드 5
 *
 *
 * 입력
 * 전위 순회한 결과
 *
 * 출력
 * 후위 순회한 결과
 *
 * 아이디어
 * 전위 순회로 결과로 트리를 만든다
 * 후위 순회를 해 출력한다.
 *
 * 세 가지 조건을 만족한다.
 * 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
 * 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
 * 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.
 */

void preOrder(int start, int end, vector<int> &tree) {
  if (start >= end) {
    return;
    // 빈 서브트리이거나 start>end일떄
  }

  // 서브트리에 노드가 하나일때
  // == 자식 노드들이 없을때
  if (start == end - 1) {
    cout << tree[start] << endl;
    return;
  }
  int idx = start + 1;

  // tree[start] 보다 큰 값을 갖는 노드를 찾는다.
  // 해당 노드를 기준으로 왼쪽 서브트리, 오른쪽 서브트리로 구분할 수 있다.
  while (idx < end) {
    if (tree[start] < tree[idx]) {
      break;
    }
    idx++;
  }

  // 왼쪽 서브트리 탐색
  // end는 해당 배열의 마지막 인덱스값보다  + 1이어야한다.
  preOrder(start + 1, idx, tree);

  // 오른쪽 서브트리 탐색
  preOrder(idx, end, tree);

  cout << tree[start] << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> tree;

  int num;
  int treeIdx = 0;

  while (!(cin >> num).eof()) {
    tree.push_back(num);
    treeIdx++;
  }

  // end는 (마지막 인덱스 +1)을 가리킨다. == 원소 개수
  preOrder(0, treeIdx, tree);

  return 0;
}