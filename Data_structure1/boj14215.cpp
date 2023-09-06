#include <iostream>
#include <vector>
using namespace std;

/* 브론즈
입력 개수가 3개 밖에 없어서

cin << a << b<< c;

if( a >= c+b) cout << 2*(c+b) -1 ;
else if( b >= a+c) cout << 2*(c+b) -1 ;
else if( c >= a+b) cout << 2*(c+b) -1 ;
else cout << a+b+c;
로 하는게 코드가 더 간결하고 좋은것 같다

 */

int another()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a >= c + b)
        cout << 2 * (c + b) - 1;
    else if (b >= a + c)
        cout << 2 * (a + c) - 1;
    else if (c >= a + b)
        cout << 2 * (a + b) - 1;
    else
        cout << a + b + c;

    return 0;
}

int boj()
{
    int n = 3, a;
    int sum = 0;
    int max = 0;

    while (n--)
    {
        cin >> a;
        if (a > max)
        {
            sum += max;
            // 이전 max의 값을 더한다.
            max = a;
        }
        else
        {
            // 현재의 값 < max
            sum += a;
        }
    }

    if (sum > max)
    {
        cout << max + sum;
        return 0;
    }

    cout << 2 * sum - 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // boj();
    another();
    return 0;
}