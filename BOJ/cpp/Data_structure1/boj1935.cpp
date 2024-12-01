#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

// N개의 다른 숫자가 들어감
// 입력은 N번만 받을 수 있음

double op_fun(char int_op, double firstNum, double secondNum)
{
    if (int_op == '+')
    {
        return firstNum + secondNum;
    }
    else if (int_op == '-')
    {
        return secondNum - firstNum;
    }
    else if (int_op == '/')
    {
        return secondNum / firstNum;
    }
    else if (int_op == '*')
    {
        return firstNum * secondNum;
    }

    // something wrong
    return 0.0;
}

double convertAlphabet(char alphabet, double *arr)
{
    return arr[alphabet - 'A'];
}

void boj1935()
{
    int N;
    cin >> N;

    string formula;
    cin >> formula;

    double arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    // 초기 세팅 끝

    stack<double> stack;
    for (int i = 0; i < formula.length(); i++)
    {
        char now = formula[i];

        if ('A' <= now && now <= 'Z')
        {
            // 알파벳임
            double num = convertAlphabet(now, arr);
            stack.push(num);
        }
        else
        {
            // 연산자임
            // 빈 경우는 일단 무시
            double num1 = stack.top();
            stack.pop();

            double num2 = stack.top();
            stack.pop();

            double result = op_fun(now, num1, num2);

            stack.push(result);
        }
    }

    // cout << fixed;
    // cout.precision(2);
    double answer = floor(stack.top() * 100.0f) / 100.0f;
    printf("%.2lf", answer);
}

int main()
{

    boj1935();
    return 0;
}
// 범위가 큰 걸 쓰는게 정확함
//  float -> double로 바꿔서 정답 처리