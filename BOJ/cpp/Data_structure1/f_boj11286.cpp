#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 최솟값 정렬
// 절댓값이 같다면, 원래의 값과 비교
// 절댓값으로 비교
// 만약 같다면 원래의 값과 비교

// priority_queue<int, vector<int>, greater<int>> pq;
// 오름차순으로 정리

vector<int> v;

int pop()
{
    if (v.empty())
    {
        return 0;
    }

    int result = v[0];
    v[0] = v[v.size() - 1];
    v.pop_back();
    int p = 0;
    int child = 2 * p + 1;

    // 1. 절댓값 형제끼리 비교
    // 1-2. 만약 같다면 원래의 값으로 비교
    // 2. 절댓값 부모 자식 비교
    // 3. 만약 같다면 원래의 값으로 비교
    // 둘의 곱으로 비교

    while (1)
    {
        if (child >= v.size())
        {
            break;
        }
        if (abs(v[child]) > abs(v[child + 1]))
        {
            child++;
        }
        if (abs(v[child]) == abs(v[child + 1]))
        {
            if (v[child] > v[child + 1])
            {
                child++;
            }
        }
        if (abs(v[p]) > abs(v[child]))
        {
            swap(v[p], v[child]);
        }
        if (abs(v[p]) == abs(v[child]))
        {
            if (v[p] > v[child])
            {
                swap(v[p], v[child]);
            }
        }
        else
        {
            break;
        }

        p = child;
    }

    return result;
}

int insert(int input)
{
    int i = v.size();
    v.push_back(input);
    // 왼쪽노드는 2*i+1

    while (i != 0 && abs(v[i]) <= abs(v[(i - 1) / 2]))
    {
        swap(v[i], v[(i - 1) / 2]);
        if (abs(v[i]) == abs(v[(i - 1) / 2]))
        {
            if (v[i] < v[(i - 1) / 2])
            {
                swap(v[i], v[(i - 1) / 2]);
            }
        }
        i = (i - 1) / 2;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int input;

    while (N--)
    {

        cin >> input;

        if (input == 0)
        {
            cout << pop() << '\n';
        }
        else
        {
            insert(input);
        }
    }

    return 0;
}