#include <iostream>
#include <vector>
#include <map>
using namespace std;

void boj()
{
    map<string, int> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        m[name]++;
    }

    pair<string, int> P = {"", -1};

    int max = 0;
    for (auto elem : m)
    {
        if (elem.second > P.second)
        {
            P = elem;
        }
    }

    cout << P.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}