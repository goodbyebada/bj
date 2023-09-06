#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minmax()
{

    int n, cnt, temp;

    cin >> n;

    while (n--)
    {

        cin >> cnt;
        int min = 100001;
        int max = -10001;

        while (cnt--)
        {

            cin >> temp;
            if (min > temp)
                min = temp;
            if (max < temp)
                max = temp;
        }

        cout << min << " " << max << "/n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    minmax();
    return 0;
}