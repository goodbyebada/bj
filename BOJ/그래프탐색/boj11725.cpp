#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

/**BFS DFS 기본문제 */

using namespace std;

queue<int> q;
int N;
vector<int> v[MAX];
int parent[MAX];
bool check[MAX];

// parent 배열에 next 인덱스에 parent 노드를 넣는다.

// 재귀버전 dfs
void dfs(int now)
{

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        // 자식 노드늘 중 하나를 선택한다.

        if (check[next])
            continue;
        // 이미 방문한 노드라면 스택에 넣지 않고 반복문으로 돌아간다

        check[next] = true;
        // 방문했음을 표시한다.
        parent[next] = now;
        // 출력할 부모 노드 배열에 now 노드를 넣는다.
        dfs(next);
        // 재귀함수로 next의 자식 노드를 탐색한다.
        // 만약 next 노드의 자식 노드가 없다면 반복문으로 돌아간다.
        // next 부모의 또 다른 인접 노드, 즉 next의 다음 형제 노드에 접근한다.
    }
}

void bfs(int now)
{

    /**
     * 첫 번째 노드를 큐에 넣는다
     * 첫번째 노드의 인접 노드들을 큐에 넣는다.
     * 맨 앞에 있는 노드를 pop한다.
     *- BFS 방식
     */

    // 자식 노드의 자식을 탐색했던 DFS와 다르게 , 형제노드부터 탐색하는 BFS이올시다.

    check[now] = true;
    // 처음노드 방문했음 체크
    q.push(now);
    // 처음 노드 큐에 넣어준다.

    while (!q.empty())
    {
        // 큐에 넣고 비울때까지 반복할 while문

        now = q.front();
        // 큐 맨 앞부터 검사한다.
        // while문을 한 번 돌고 왔을시 now 노드 업데이트
        // 형제 노드부터 방문한다.

        // now의 인접 노드들을 큐에 넣는다.
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            // now의 인접 노드가 next

            // 방문하지 않은 노드라면
            if (!check[next])
            {
                q.push(next);
                // 큐에 넣는다.
                check[next] = true;
                // 방문했음을 체크한다.
                parent[next] = now;
                // 부모 배열에 Next 인덱스에 부모 노드를 넣는다.
            }
        }

        q.pop();
        // 큐의 맨 앞에 있는 Now 노드를 pop 시켜 없앤다.
    }
}

void solutionDFS()
{
    check[1] = true;
    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
}

void solutionBFS()
{

    bfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    solutionBFS();

    return 0;
}