#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100000

// 변수 선언
vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int parent[MAX_N + 1];

/*
*
부모노드를 출력하는 문제.
 DFS 문제
루트 노드를 시작으로 DFS 탐색을 진행하며 부모-자식 관계를 정해준다.
*/

void DFS(int x) {

    // 노드 x에 연결된 간선을 살펴봅니다.
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];
        // 아직 방문해본적이 없는 노드라면
        // 트리의 부모-자식 관계가 결정됩니다.
        // 부모는 x, 자식이 y가 됩니다.
        if (!visited[y]) {
            visited[y] = true;
            parent[y] = x;

            // 추가적으로 탐색을 더 진행합니다.
            DFS(y);
        }
    }
}

int main() {

    int n;
    cin >> n;

    // 간선에 대한 정보
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        edges[parent].push_back(child);
        edges[child].push_back(parent);
    }

    visited[1] = true;
    DFS(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    };

    return 0;
}