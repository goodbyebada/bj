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

  while (1) {
    for (int i = 0; i < n; i++) {
      d.push_back(originDeque[i]);
    }
    for (int i = originDeque.size() - 1; i >= originDeque.size() - n; i--) {
      d.push_back(originDeque[i]);
    }

    for (int i = 0; i < n; i++) {
      originDeque.pop_front();
      originDeque.pop_back();
    }

    // if (originDeque.size() - (2 * n) <= 0) {
    //   break;
    // }

    if (originDeque.size() <= (2 * n)) {
      break;
    }
  }

  // 남아있는 원소 추가
  for (int i = 0; i < originDeque.size(); i++) {
    answerd.push_back(originDeque[i]);
  }
  // 섞은 원소 추가
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

  for (int n : num_vec) {
    originDeque = sol(n);  // originDeque 갱신
  }

  for (int num : originDeque) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
