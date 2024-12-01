#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define endl '\n'
#define ull unsigned long long
using namespace std;

/*
1) 8진수를 2진수로 변환하여 출력한다
2) 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

sol)
1. 이진수로 바꾸는 함수 작성
2로 계속 나누는 수밖에..

숫자 하나마다 세자리수로 나타낸다
2의 제곱수로 나타낸다

314



3 % 2
3/2

1) 홀수일때
--1
cnt로 n제곱을 센다
n 자리수에 넣는다

2) 짝수일때
--0

10의 배수로 잘라서 3등분한다

vector에 순서대로 push한다
v[0]이 0이라면 index 1부터 출력한다


*/

stack<int> st;
bool flag = false;

int boj()
{

    int testNum;
    cin >> testNum;

    if (testNum == 0)
    {
        cout << 0;
        return 0;
    }

    int i = 1;
    int cnt;
    while (testNum != 0)
    {
        if (testNum / (10 ^ i) < 0)
        {
            break;
        }

        // ex) 314
    }
}

// int boj()
// {
//     ull testNum;
//     cin >> testNum;

//     if (testNum <= 0)
//     {
//         cout << 0;
//         return 0;
//     }

//     while (testNum > 0)
//     {
//         int single = testNum % 10;

//         for (int i = 0; i < 3; i++)
//         {
//             st.push(single % 2);
//             single /= 2;
//         }

//         testNum /= 10;
//     }

//     while (!st.empty())
//     {

//         if (st.top() == 1)
//         {
//             flag = true;
//         }
//         if (flag)
//         {
//             cout << st.top();
//         }

//         st.pop();
//     }

//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}