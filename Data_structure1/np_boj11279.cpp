#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

/*
왼쪽 자식의 인덱스 = 부모 인덱스 * 2 + 1
오른쪽 자식의 인덱스 = 부모 인덱스 * 2 + 2
부모 인덱스 = 자신 인덱스 - 1 / 2
*/

void push(int data)
{
    int i = v.size();
    v.push_back(data);

    // index가 0일때는 비교를 안한다
    while (i != 0 && v[i] > v[(i - 1) / 2])
    {
        swap(v[i], v[(i - 1) / 2]);
        i = (i - 1) / 2;
        // 부모노드로 올라가서 비교해야하니까 index를 부모노드 인덱스로
        // i==0일될때 탈출
    }
}

int pop()
{
    if (v.size() == 0)
    {
        return 0;
    }

    int result = v[0];
    v[0] = v[v.size() - 1];
    v.pop_back();

    int p = 0;
    while (1)
    {
        int child = p * 2 + 1;
        // 왼쪽 자식 노드
        if (child >= v.size())
        {
            break;
            // 더 이상 자식이 없을때
        }

        if (v[child] < v[child + 1])
        {
            child++;
            // child++해서  오른쪽 자식 인덱스로
        }

        if (v[child] > v[p])
        {
            swap(v[child], v[p]);
            p = child;
            // child 인덱스가 부모가 된다
        }
        else
        {
            // 부모노드가 자식노드보다 크면
            break;
        }
    }
    return result;
}

int main()
{
    int test;

    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int input;
        scanf("%d", &input);

        if (input == 0)
        {
            printf("%d\n", pop());
        }
        else
        {
            push(input);
        }
    }

    return 0;
}