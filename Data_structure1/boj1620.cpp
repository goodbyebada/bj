#include <iostream>
#include <map>
#include <vector>
// #include <unordered_map>
using namespace std;

int boj1620()
{
    int n, m;

    cin >> n >> m;

    map<string, int> map;
    vector<string> v = {"zero"};

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        map[name] = i;
        v.push_back(name);
    }

    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        if (input[0] <= 64)
        {
            cout << map[input] << '\n';
        }
        else
        {
            cout << v[stoi(input)] << '\n';
        }
    }

    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    boj1620();
    return 0;
}