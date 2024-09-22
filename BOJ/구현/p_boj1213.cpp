#include <iostream>
using namespace std;
string s, ans;

int alpha[26];
// A~Z까지 26

bool canNotMakePalin()
{
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (alpha[i] % 2 == 1)
            cnt++;
    return cnt > 1;

    // value가 1인 알파벳이 1개 이상이라면 return 1;
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        alpha[s[i] - 'A']++;
    // 사전순으로 인덱스가 들어감..!!!

    if (canNotMakePalin())
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    // 안되는거 먼저 걸러줘서 시간 단축

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < alpha[i] / 2; j++)
            ans += i + 'A';

    for (int i = 0; i < 26; i++)
        if (alpha[i] % 2)
            ans += i + 'A';
    // nonZero => 홀수라면 -> 나머지 1 짝수개수의 알파벳들 나열후 마지막에 넣어야하니까
    // 이또한 사전순 + 마지막에 넣어야하니까 한번 더 반복문

    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < alpha[i] / 2; j++)
            ans += i + 'A';
    // alpha배열을 뒤에서부터 검사한다
    // string에 덧붙인다.

    cout << ans << '\n';
}