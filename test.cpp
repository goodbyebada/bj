#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

int boj()
{
    time_t t, end;
    t = time(NULL);
    printf("%d\n", t);
    double i = 0;
    while (i < 10000000000)
    {
        i++;
    }
    end = time(NULL);
    printf("end : %d\n", end);
    printf("duration : %d\n", end - t);
    return 0;

    // time_t start, finish;
    // int duration;
    // int test = 0;

    // start = time(NULL);
    // printf("%f초\n", start);

    // for (int i = 0; i < 50000; i++)
    // {
    //     for (int k = 0; k < 50000; k++)
    //         test++;
    // }

    // finish = time(NULL);
    // printf("finish :%f초\n", finish);

    // duration = (finish - start);

    // if (duration == 2)
    // {
    //     printf("dration :%f초\n", duration);
    //     printf("test : %d\n", test);
    // }

    // return 0;

    // while (duration > 20)
    // {
    //     start = time(NULL);

    //     gc_write_cnt++;
    //     ssd_write_cnt++;

    //     finish = time(NULL);

    //     printf("duration = %d", duration);

    //     duration = (int)(finish - start);

    //     if (duration % 10 == 0)
    //     {
    //         int WAF = (gc_write_cnt + ssd_write_cnt) / ssd_write_cnt;

    //         printf("%d", WAF);
    //     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}