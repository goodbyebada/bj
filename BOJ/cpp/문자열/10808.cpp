#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 26

/*
브론즈 4
1:55 ~

단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

1.map을 사용한다 ->
단어의 길이 100을 넘지 않는다
26(map 생성) + 26 * 100 + 26( 출력할때 ) -> 1초 넘지 않는다

2.그럼 그냥 배열로 해도 된다.
char을 숫자로 바꿔서 배열의 인덱스로 선언

1. char형을 인덱스로 선언한다.
2. -97 통해 인덱스 설정.
3. char를 숫자로 인식한 후 해당 인덱스의 값을 ++ 해준다.
4. 하나씩 출력한다.

*/

int boj()
{
    int arr[MAX] = {0};
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {

        int num = str[i];
        arr[num - 97]++;
    }

    for (int i = 0; i < MAX; i++)
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