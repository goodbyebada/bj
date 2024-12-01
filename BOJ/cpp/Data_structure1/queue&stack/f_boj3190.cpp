#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * 골드4 뱀
 * 1H 30M ~
 * 구현능력 부족으로 답지를 봤다.
 *
 * 맨위, 맨좌측 위치
 * 뱀의 길이는 1
 *
 * 처음은 오른쪽으로 간다.
 * 매 초마다 이동한다.
 * 몸길이를 늘려 머리를 다음칸에 위치
 * 벽과 자기 자신의 몸과 부딪히면 끝난다.
 * -- 이동시
 * 사과가 있다면 사과가 없어지고 그대로 다음칸으로 이동
 * 사과 X, 꼬리가 위치한 칸을 비워준다.
 *
 *
 * 최종 목표 : 이 게임이 몇 초에 끝나는가?
 *
 *  [y][x]
 *
 *
 * [0,0,0,0]
 * [0,0,0,0]
 * [0,0,0,0]
 * [0,0,0,0]
 * -- 풀이 1.
 * 1. 한칸씩 움직일때 마다 1초가 걸린다.
 * 2.
 *
 * 뱀의 길이 정보 - 큐  꼬리의 정보 맨 앞 계속 pop()
 *
 * 내가 가려는 곳에 확인하려면 벡터 다 순회
 *
 * 아웃 조건 -> 벽 , 몸통
 * 1. 뱀의 위치 넣는 큐를 만든다. [] LIFO
 * 사과가 없다면 pop()
 * 사과가 있다면 가만히
 * 2. 본인 몸이라는 건 어케 확인? vector 순회,, N^2
 * 3. 오른쪽 왼쪽 판단은 어떻게?
 *  방향에 대한 정보도 기억하고 있어야한다.
 *  -> x쪽으로 증가/감소했다면 방향 전환시 y축 위아래로
 *  -> y쪽으로 증가감소했다면 방향 전환시 x축 좌우로
 *  -> flag로 관리
 * 4. 한칸 이동할때마다 초 cnt 변수 이용
 *
 * 보드의 크기 N
 *
 *
 *
 */

// y x
deque<pair<int, int>> dq;

int checkApple(int *board[][], int y, int x) {
  //   사과가 없다면
  if (!board[y][x]) {
    if (!dq.empty()) {
      dq.pop_front();
    }
  }
}

int checkDirection() {}

// L R 마주쳤을때 뱀의 좌표
pair<int, int> direction(char C) {
  pair<int, int> p1 = dq[dq.size() - 1];
  pair<int, int> p2 = dq[dq.size()];

  int beforeY = p1.first;
  int beforeX = p1.second;

  int afterY = p2.first;
  int afterX = p2.second;

  pair<int, int> nowP;

  //   [y][x]

  //   L이라면
  // X가 커졌다면 Y+1
  // Y가 커졌다면 X-1

  //   R이라면
  // X가 커졌다면 Y-1
  // Y가 커졌다면 X+1

  nowP = p2;

  if (C == 'L') {
    if (afterX > beforeX) {
      nowP.second = afterX - 1;
    } else if (afterX < beforeX) {
      nowP.second = afterX + 1;
    }

    if (afterY > beforeY) {
      nowP.first = afterY - 1;
    } else if (afterY < beforeY) {
      nowP.first = afterY + 1;
    }
  }

  if (C == 'D') {
    if (afterX > beforeX) {
      nowP.first = afterY - 1;
    } else if (afterX < beforeX) {
      nowP.first = afterY + 1;
    }
    if (afterY > beforeY) {
      nowP.second = afterX + 1;
    } else if (afterY < beforeY) {
      nowP.second = afterX - 1;
    }
  }

  return nowP;
}

int boj() {
  int N, K, DirectionCnt;

  cin >> N;
  cin >> K;

  int appleX, appleY;

  //   1행 1열이기 때문에
  int board[N - 1][N - 1];
  vector<pair<int, char>> directionV;

  // 사과는 1이다.
  while (K--) {
    // 행 appleY
    //  열  appleX
    cin >> appleY >> appleX;
    board[appleY - 1][appleX - 1] = 1;
  }
  cin >> DirectionCnt;

  while (DirectionCnt--) {
    int count;
    char D;
    cin >> count >> D;
    directionV.push_back({count, D})
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //   boj();

  return 0;
}