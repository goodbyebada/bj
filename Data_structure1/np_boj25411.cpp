#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// int boj()
// {

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int test;
//         cin >> test;
//         if (a[i])
//         {
//             continue;
//         }
//         b.push_back(test);
//     }
//     int m;
//     cin >> m;

//     while (m--)
//     {
//         int test;
//         cin >> test;
//         b.push_front(test);
//         cout << b.back() << ' ';
//         b.pop_back();
//     }

//     return 0;
// }

int main()
{
    bool a[10000];
    deque<int> b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int test;
        cin >> test;
        if (a[i])
        {
            continue;
        }
        b.push_back(test);
    }
    int m;
    cin >> m;

    while (m--)
    {
        int test;
        cin >> test;
        b.push_front(test);
        cout << b.back() << ' ';
        b.pop_back();
    }
    return 0;
}
