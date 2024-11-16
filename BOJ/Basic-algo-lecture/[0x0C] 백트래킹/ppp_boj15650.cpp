#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 8
#define endl '\n'
/**
 *  1부터 n까지 중복 없이 m개를 골라야한다.
 */
int n, m;

vector<int> v;
vector<int> tmp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    v.push_back(i + 1);
    tmp.push_back(0);
  }

  for (int i = tmp.size() - 1; i >= m; i--) {
    tmp[i] = 1;
  }

  sort(v.begin(), v.end());

  do {
    for (int i = 0; i < v.size(); i++) {
      if (tmp[i] == 0) cout << v[i] << " ";
    }
    cout << endl;
  } while (next_permutation(tmp.begin(), tmp.end()));
  return 0;
}