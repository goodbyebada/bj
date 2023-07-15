#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
    stack<int> s;
    vector<char> result;
    // result라는 벡터 사용

    int cnt = 1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        while (cnt <= x)
        {
            s.push(cnt);
            cnt += 1;
            result.push_back('+');
        }
        // cnt == 입력 횟수 ==  stack에  들어갈 수

        // cnt > x
        // 입력횟수보다 stack에 있는 원소값보다 크다면
        // s.top()과 입력 받은 x의 값이 같은지 검사
        if (s.top() == x)
        {
            cout << "pop전에 s.top(): " << s.top() << '\n';
            s.pop();
            result.push_back('-');
        }
        else
        {
            //  cnt > x
            // 다시 넣었다 빼는게 안되는거니 s.top()이 x랑 다르다면
            // top보다 인덱스가 작은 원소를 삭제 해야함 => 안됨
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }
}

// 왜 NO가 되는지 제대로 생각하삼...