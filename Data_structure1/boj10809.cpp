#include <iostream>
#include <vector>
#include <map>
#define N 26
using namespace std;

//  0~25 a~z 배열로 만들기
// 들어오는 입력 char int로 찾아서 현재 인덱스 넣어두기

int boj()
{
    string str;
    cin >> str;
    int n = str.size();

    int arr[N];

    for (int i = 0; i < 26; i++)
    {
        arr[i] = -1;
    }

    for (int i = 0; i < str.size(); i++)
    {
        int c = str[i];
        if (arr[c % 97] == -1)
        {
            arr[c % 97] = i;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}