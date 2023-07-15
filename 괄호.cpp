#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int n1 = 0;
        char a[51];

        scanf("%s", a);
        // char a string 값으로 받

        int z = 0;

        while (a[z] != '\0')
        {
            // 끝이 ('\0' )아니라면 반복문을 계속한다.

            if (a[z] == '(')
                n1++;
            if (a[z] == ')')
                n1--;
            if (n1 < 0)
            {
                printf("NO\n");
                break;
            }
            z++;
            // 인덱스값 중가
        }
        if (n1 == 0)
            printf("YES\n");
        else if (n1 > 0)
            printf("NO\n");
    }
}