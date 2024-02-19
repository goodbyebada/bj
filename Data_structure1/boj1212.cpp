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

sol
1. int testNum으로 받는다
2. testNum% 10 -> 끝에 있는 자리 수만큼 자른다
testNum /= 10 0이 될때까지 실행한다
3. 3번 반복한다 -> n%2
while( q <3 )
int q = 0
int total = 10**q + n%2
n/=2;
q++

-> 3번 반복
4. 스택에 저장한다
5. 끝나면 2번으로 돌아간다
6. 0이 되면 스택이 empty가 될때까지 출력한다 단, 맨 처음 pop할때 0인 애들은 출력하지 않는다 그 이후로는 pass


------ 틀린이유
1) 자리수
int 2^32 bit 10자리를 넘는 값을 표현할 수 없다.
주어지는 수의 길이는 333,334을 넘지 않는다.
따라서 int로 받으면 overflow

2) 반례 0일때 => 수가 0인 경우를 제외하고 반드시 1로 시작해야한다.

수의 길이!!!!! 0일때!! 문제를 잘 읽자..


*/

stack<int> st;
bool flag = false;

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

int boj() {}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}