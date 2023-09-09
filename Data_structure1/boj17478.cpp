#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define endl "\n"
using namespace std;

/*
재귀함수
*/

void boj(int n, string str)
{

    cout << str + "\"재귀함수가 뭔가요?\"" << endl;
    if (n > 0)
    {
        cout << str + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
        cout << str + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
        cout << str + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
        string plus = "____";
        n--;
        boj(n, str + plus);
    }
    else if (n == 0)
    {
        // cout << str + "\"재귀함수가 뭔가요?\"" << endl;
        cout << str + "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
    }

    cout << str + "라고 답변하였지." << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    string str = "";
    boj(T, "");

    return 0;
}
