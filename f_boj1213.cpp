#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

/*
12:05~ 1:42 실패!!! ㅠㅠㅠ 아닌것 같음 ..
2s


1.팰린드롬인 문자열 : 거꾸로 읽어도 똑같은 문자열
2. 알파벳순으로 나열해야한다
3. 만약 팰린드롬 알고리즘이 아니라면 I'm Sorry Hansoo 출력

1) 문자열을 받는다
- 팰린드롬 문자열인지 확인해야한다
- 알파벳순으로 되어있는지 확인해야한다
2) 홀수인 애는 가운데에 있어야함

test가 알파벳이 순서대로 온다는 가정하에
사전순으로 앞서는 것을 출력한다.

1) pair 사용
2) key 알파벳 , value = 갯수
3) 문자열 검사 후 , 알파벳 별로 갯수를 체크한다.
- 짝수라면 /2 한 횟수만큼 알파벳순으로 벡터에 넣는다.
- 홀수라면 /2 한 횟수만큼 알파벳순으로 벡터에 넣는다. 남은 1개는 짝수인 알파벳이 들어간 후 마지막으로 넣는다.
- 홀수라면 index -2 부터 접근해서, 짝수라면 -1접근해서, 거꾸로 다시 넣는다

아닌것 ) abcddba -> 홀수가 2개 이상라면 팰린드롬이 아니다.

 */

void copy();

int exist(string str, int now, vector<pair<char, int>> &check)
{
    for (int i = 0; i < check.size(); i++)
    {
        if (str[now] == check[i].first)
        {
            check[i].second++;
            return 1;
            // 같은  알파벳이 있다면
        }
    }

    return 0;
    // 같은 알파벳이 없다면 0 리턴
};

int boj()
{

    string str;
    cin >> str;
    vector<pair<char, int>> check;
    vector<char> ans;

    int checkCnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int cnt = 1;
        if (check.empty())
        {
            check.push_back({str[i], cnt});
            // index가 0일때
        }

        if (!exist(str, i, check))
        {
            check.push_back({str[i], cnt});
        }

        checkCnt++;
    }
    sort(check.begin(), check.end());
    // 오름차순으로 정렬 -> 사전순으로 나와야하니까

    // for (const auto &n : check)
    // {

    //     cout << n.first << n.second;
    // }

    if (checkCnt % 2 == 0)
    {
        // 문자열의 길이가 짝수
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i].second % 2 == 0)
            {
                // 짝수의 개수라면
                int cnt = check[i].second / 2;
                while (cnt--)
                {
                    ans.push_back(check[i].first);
                }
            }
            else
            {
                cout << "I'm Sorry Hansoo";
                // 안되는 조합이올시다.
            }
        }

        int cnt = checkCnt / 2;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ans.push_back(ans[i].first);
            // 왜 빨간 것이..
        }
    }
    else
    {
        // 문자열의 길이가 홀수이다
        //  홀 + 짝
    }

    // copy();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    boj();
    return 0;
}