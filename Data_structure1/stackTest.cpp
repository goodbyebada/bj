#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #pragma warning(disable : 4996)

int top = 0;

void push(int *stack)
{

    int *stack = stack;
    // stack 은 주소
    //*stack은 값 -> stack
    //????

    int domy;
    scanf("%d", &domy);
    stack[top] = domy;
    top++;
    return;
}

void pop(int *stack)
{
    if (top == 0)
    {
        printf("%d\n", -1);
        return;
    }
    // stack 배열의 인덱스가 0이라면 -1 출력 후 종료

    printf("%d\n", stack[top - 1]);
    // 아니라면 맨 뒤에서 -1 값 출력 -> pop이니까
    // top 인덱스 줄이기
    top--;
}

int main()
{

    int size;
    char triger[10];

    scanf("%d", &size);
    int *stack = (int *)malloc(sizeof(int) * size);

    //?? 왜 포인터가 붙어있는걸까
    // int size가 size개 만큼 할당

    for (int i = 0; i < size; i++)
    {
        scanf("%s", triger);
        // string으로 받는게 왜..

        if (strcmp(triger, "push") == 0)
            push(stack);
        else if (strcmp(triger, "size") == 0)
            printf("%d\n", top);
        else if (strcmp(triger, "pop") == 0)
            pop(stack);
        else if (strcmp(triger, "empty") == 0)
            printf("%d\n", top == 0);
        else if (strcmp(triger, "top") == 0)
        {
            if (top == 0)
                printf("%d\n", -1);
            else
                printf("%d\n", stack[top - 1]);
        }
    }
    free(stack);
    return 0;
}