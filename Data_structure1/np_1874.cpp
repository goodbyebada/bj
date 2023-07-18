#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 1. 스택 이용
// 2. 원하는 애가 나올 때까지 계속 스택에 push, 오름차순이기에 cnt 카운트와 동일
//   a. cnt > x : stack에 x가 들어가있다.
// 3. 원하는 값이 stack에 들어갔을때 pop(), x == stack.top()
// 4. "NO" 조건 : stack에서 pop() 하면 삭제됨, 한번 꺼낸 애는 영원히 삭제!
// 5. 그렇기에 stack에 x가 들어가있지만, top()이 아니라면 안되는 조건

// 1. 스택 사용
// 2. x ( 입력값)이 나올때까지 stack에 계속 push, result 큐에 + push
// 3. 스택의 top이 x와 같다면, stack.pop(), result 큐에 - push
// 4. 아니라면 안되는 조건, NO 출력 후 바로 종료
// 5. 반복문을 통해 result의 값들 출력

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