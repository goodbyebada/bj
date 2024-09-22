#include <iostream>
using namespace std;
#include<utility> 
#include <vector>

/**
 * @brief
 * sol1) DFS로 접근
 * 루트노드를 기준으로,  가장 긴 길이를 가진 자식노드의 누적길이를 더한다.
 * 2 ≤ n ≤ 100,000이기 때문에  최대일 경우 1초 넘을 수 있음
 *
 */
using namespace std;
#define MAX_N 100000
vector<pair<int, int>> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int parent[MAX_N + 1];

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    for (int i = 0; i < n; i++) {
        int x, y;
        int len;
        cin >> x >> y >> len;

        edges[x].push_back({y, len});
        edges[y].push_back({x, len});

        cout << edges[y]<<endl;

    }

    return 0;
}