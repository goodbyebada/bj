#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct info
{
    int pos, is_open, idx;
};

int n, x, r;
vector<info> v;
stack<int> s;

bool compare(const info &a, const info &b)
{
    return a.pos < b.pos;
    // 오름차순
}

bool solution()
{
    for (int i = 1; i < v.size(); i++)
        if (v[i - 1].pos == v[i].pos)
            return 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].is_open)
            s.push(v[i].idx);
        else if (v[i].idx == s.top())
            s.pop();
        else
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> r;
        v.push_back({x - r, 1, i});
        v.push_back({x + r, 0, i});
    }

    sort(v.begin(), v.end(), compare);

    cout << (solution() ? "YES" : "NO");
}