#include <iostream>
#include <stack>
#include <queue>
#include <typeinfo>

using namespace std;

float op(char op, float firstNum, float secondNum)
{
    if (op == '+')
    {
        return firstNum + secondNum;
    }
    else if (op == '-')
    {
        return firstNum - secondNum;
    }
    else if (op == '/')
    {
        return firstNum / secondNum;
    }
    // else (op == '*')
    // {
    return firstNum * secondNum;
    // }
}

int boj1935()
{
    int N;
    float arr[50];
    stack<float> s;
    queue<float> q;
    int index = 0;
    char *singleChar;
    string stringInput;
    // cin >> N;
    char char_input;

    // 문제 1) 대문자 들어왔을때 0으로 저장해버림
    // 해결 ) input을 int 형으로 지정해놨었음

    // 비교하는 애를 큐로 놓아보자

    // cin >> stringInput;
    // cout << stringInput;
    // 문자가 두개일때만 segmentaiton fault가 안남

    cin >> char_input;
    q.push(char_input);
    cout << q.front();

    //     while (stringInput[index] != '\0')
    // {

    //     arr[index] = stringInput[index];
    //     // float 형 배열로 각각의 값 저장
    //     index++;
    // }

    // cout << "Done";

    // 어헝 뇌절온다
    // ABC*+DE/-를 배열로 받고 싶었는데 끝일때 어떻게 탈출하는지를 몰러..
    // string 비교로 하자
    // 포인터 쓰고 싶은데 기억 안난다
    //  *char = string 안됨???
    //  왜 안됨 ㅠㅠㅠ

    // for (int i = 0; i < stringInput.length(); i++)
    // {

    //     if (arr[index] > 64) // 문자라면
    //     {
    //         cin >> input;
    //         s.push(input);
    //         // cout << "문자 들어옴";
    //         // 문자라면 숫자 input을 push
    //     }
    //     else
    //     {
    //         // 연산자라면
    //         float secondNum = s.top();
    //         s.pop();
    //         float firstNum = s.top();
    //         s.pop();

    //         s.push(op(arr[index], firstNum, secondNum));
    //     }
    //     index++;
    //     // cout << "현재 s.top()" << s.top();

    //     if (s.size() == 1)
    //     {
    //         cout << s.top();
    //         return 0;
    //     }
    // }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    boj1935();
    return 0;
}