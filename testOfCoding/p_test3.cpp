#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int c, p;
vector<int> num_vec;
deque<int> originDeque;

deque<int> sol(int n) {
  deque<int> d;
  deque<int> answerd;

  // 미리 계산하고 실행한다.
  while (originDeque.size() > 2 * n) {
    for (int i = originDeque.size() - 1; i >= originDeque.size() - n; i--) {
      d.push_front(originDeque[i]);  // 뒤에서 n개
    }

    for (int i = n - 1; i >= 0; i--) {
      d.push_front(originDeque[i]);  // 앞에서 n개
    }

    for (int i = 0; i < n; i++) {
      originDeque.pop_front();  // 앞에서 제거
      originDeque.pop_back();   // 뒤에서 제거
    }
  }

  // 남아있는 원소를 먼저 넣기
  for (int i = 0; i < originDeque.size(); i++) {
    answerd.push_back(originDeque[i]);
  }
  // 섞인 d를 뒤에 붙이기
  for (int i = 0; i < d.size(); i++) {
    answerd.push_back(d[i]);
  }

  return answerd;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c;
  cin >> p;

  for (int i = 0; i < c; i++) {
    originDeque.push_back(i + 1);
  }

  for (int i = 0; i < p; i++) {
    int num;
    cin >> num;
    num_vec.push_back(num);
  }

  int level = 0;
  for (int n : num_vec) {
    originDeque = sol(n);  // originDeque를 갱신
  }

  for (int i = 0; i < 5; i++) {
    cout << originDeque[i] << " ";
  }

  cout << endl;

  return 0;
}
