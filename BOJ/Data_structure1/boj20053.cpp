#include <iostream>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T, max, min, temp;

    cin >> T;

    while (T--)
    {

        max = -1000000;
        min = 1000000;

        cin >> N;

        while (N--)
        {
            cin >> temp;
            if (max < temp)
                max = temp;
            if (min > temp)
                min = temp;
        }

        cout << min << " " << max << "\n";
    }
}