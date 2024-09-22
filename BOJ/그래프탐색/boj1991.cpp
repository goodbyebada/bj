#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
using namespace std;

/**
 * 노드 / 왼쪽 자식 노드 / 오른쪽 자식 노드
 *
 * 1.전위순회
 * 2.중위순회
 * 3.후위순회
 */

vector<char> v[MAX];
stack<char> s;
bool visited[MAX];
int LEFT_INDEX = 0;
int RIGHT_INDEX = 1;

// 전위순회

// 왼쪽 탐색을 우선
// 현재 노드 먼저 출력
// 왼쪽 노드 탐색
// 왼쪽노드가 없다면 오른쪽 노드를 탐색한다.
// '.' 는 제외한다

int before(char first)
{

    char now = v[first][LEFT_INDEX];
    s.push(now);
    cout << s.top();
    visited[now] = true;

    while (!s.empty())
    {
        char next = v[now][LEFT_INDEX];
        s.push(next);
        

        if (visited[next])
        {
            s.pop();
            continue;
        }

        if (next == '.')
        {
            next = v[now][RIGHT_INDEX];
            if (next == '.')
            {
                visited[next] = true;
                s.push(next);
            }
        }

        s.push(next);
    }
}

// 후위순회
int after_cir()
{
}

// 중위순회
int center_cir()
{
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while (N--)
    {
        char now, left, right;
        cin >> now >> left >> right;
        cout << now << left << right;

        v[now].push_back(left);
        v[now].push_back(right);
    }
    return 0;
}
