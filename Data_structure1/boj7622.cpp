#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
BOJ7622

1.이중우선 순위 큐에는 삽입, 삭제 두 가지의 연산 존재
2.삭제는 최댓값 삭제 , 최솟값 삭제 두 가지의 삭제 유형을 가짐
3. 저장된 값이 우선순위
4. 최댓값과 최솟값 출력

- 출력
1. 입력의 첫번째줄 데이터 개수 T개
2. 연산의 개수
3. I n - n을 삽입, D 1 최댓값 출력, D -1 최솟값 출력
4. 최댓값이 2개 이상일 때 하나만 삭제, 동일한 정수 삽입될 수 있음
5. Q가 비어있을때 D라면 무시해도 됨

- bruteForce : 6초
1) deque 사용 -> 정렬하기 편하니까
2) 삽입할때마다 sort
->6초라서 될 것 같았는데 시간 초과 => 왜?

- heap log n * n
최대 최소만 가려내면 되니까 맨 위에 있는 부모노드 , 아래에 있는 자식 노드만 하면 될 것 같은데
맨 아래에 있는것이 최소라는 보장이 없음 -> 두 개 쓰는게 낫다!

-- 검색함
1) minHeap/maxHeap => 정렬 O(nlogN)/ 삽입,삭제 O(logN)
2) set/map => 같은 정수가 들어갈 수 있기 때문이다
3) minHeap maxHeap 같은 수가 있는지 동기화를 시켜줘야 함 -> set,map, 배열
4) Pop하기 전, 현재 heap이 valid한 값으로 되어있는지 재정렬한다

++) struct Node {
    bool valid
    int i
}
구조체를 heap에 넣으면 같은 객체이기 때문에 일일이 배열을 선언해서 valid 한지 확인할 필요없다
같은 객체이기에 자동 동기화
 */

// D I를 처리할 함수

int syncMaxHeap(priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> &maxHeap, bool valid[])
{

    while (!maxHeap.empty() && !valid[maxHeap.top().second])
    {
        maxHeap.pop();
    }
    return 0;
};

int syncMinHeap(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &minHeap, bool valid[])
{

    while (!minHeap.empty() && !valid[minHeap.top().second])
    {
        minHeap.pop();
    }
    return 0;
};

int play(int cnt)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
    // 내림차순
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    // 오름차순

    bool valid[1000001];
    // 중복되는 숫자 확인 용 -> 순서 i번째로 확인

    for (int i = 0; i < cnt; i++)
    {
        char c;
        int num;
        cin >> c >> num;

        if (c == 'I')
        {
            minHeap.push({num, i});
            maxHeap.push({num, i});
            valid[i] = true;
        }
        else
        {
            // D일 경우

            if (num > 0)
            {
                // 최댓값을 비교한다
                syncMaxHeap(maxHeap, valid);
                if (!maxHeap.empty())
                {
                    valid[maxHeap.top().second] = false;
                    maxHeap.pop();
                }
            }
            else
            {
                // 최솟값을 비교한다
                syncMinHeap(minHeap, valid);
                if (!minHeap.empty())
                {
                    valid[minHeap.top().second] = false;
                    minHeap.pop();
                }
            }
        }
    }

    syncMaxHeap(maxHeap, valid);
    syncMinHeap(minHeap, valid);
    // 마지막 valid 배열에 업데이트에 대한 동기화

    if (minHeap.empty())
    {
        cout << "EMPTY\n";
    }
    else
    {
        cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int cnt;
        cin >> cnt;
        play(cnt);
    }

    return 0;
}