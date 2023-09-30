#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <map>

// 9:05 ~ 9:17

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    // 여기에 코드를 작성해주세요.

    int num;
    int nowX = 0, nowY = 0;

    cin >> num;

    while (num--)
    {
        pair<char, int> p;
        int dist_num;
        cin >> p.first >> p.second;

        //     if (p.first == 'E')
        //     {
        //         dist_num = 0;
        //     }
        //     else if (p.first == 'S')
        //     {
        //         dist_num = 1;
        //     }
        //     else if (p.first == 'W')
        //     {
        //         dist_num = 2;
        //     }
        //     else if (p.first == 'N')
        //     {
        //         dist_num = 3;
        //     }

        // 어떤값이 들어갔을때 뭐가 나왔으면 좋겠다 => Map 으로 코드길이 줄이기

        unordered_map<char, int> dir_map = {{'E', 0}, {'S', 1}, {'W', 2}, {'N', 3}};

        dist_num = dir_map[p.first];

        nowX += dx[dist_num] * p.second;
        nowY += dy[dist_num] * p.second;
    }

    cout << nowX << " " << nowY;
    // 깔끔하구먼... 반복되는 부분은 제외하자
    // 좌표에서는 반복을 간단연산으로 할수있다 굳이 while문 돌리지말자.. 더럽다..

    return 0;
}