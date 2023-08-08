#include <iostream>
// #include <unordered_set>
#include <map>
using namespace std;

int boj14425()
{

    int n, m;
    cin >> n >> m;

    map<string, int> hashmap;
    // unordered_set<string> hashmap;
    while (n--)
    {
        string answer;
        cin >> answer;
        hashmap[answer] = 1;
        // hashmap.insert(answer);
    }

    int cnt = 0;
    while (m--)
    {
        string test;
        cin >> test;

        if (hashmap.find(test) != hashmap.end())
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    boj14425();
}