#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string func(string string)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<char> q;

    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] == ')')
        {
            if (!q.empty())
            {
                q.pop();
            }
            else
            {
                return "NO";
            }
        }
        else
        {
            q.push(string[i]);
        }
    }

    if (!q.empty())
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    char c;
    string string;

    cin >> N;

    while (N--)
    {
        cin >> string;
        cout << func(string) << endl;
    }

    return 0;
}