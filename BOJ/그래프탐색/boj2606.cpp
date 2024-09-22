#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> nodes[10000];
bool visited[10000] = {false};
int bfsInLinkedList(int now);
string log = "log";

int boj()
{
    int N, E;

cin >> N;
    cin >> E;

    int N1, N2;

    for (int i = 0; i < E; ++i)
    {
        cin >> N1 >> N2;
        nodes[N1].push_back(N2);
        nodes[N2].push_back(N1);
    }

    int result = bfsInLinkedList(1);
    cout << result - 1 << endl;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    // test();
    return 0;
}

int bfsInLinkedList(int now)
{
    queue<int> q;
    int cnt = 0;
    q.push(now);
    visited[now] = true;

    while (!q.empty())
    {
        now = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < nodes[now].size(); i++)
        {
            int next = nodes[now][i];
            // 노드 이름

            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return cnt;
}

void bfsInMatrix(int now)
{

    queue<int> q;
    q.push(now);
    visited[now] = true;

    int N = nodes[now].size();

    while (!q.empty())
    {

        now = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {

            if (nodes[now][i] == 1 && !visited[now])
            {
                int next = nodes[now][i];

                visited[next] = true;
                q.push(next);
            }
        }
    }
}