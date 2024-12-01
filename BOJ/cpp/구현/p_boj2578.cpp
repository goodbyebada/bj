#include <iostream>
using namespace std;
#define MAX 5
/**
 * 1. 문제 구해야하는 것과 특징을 먼저 적어놓자.
 *
 *
 * 빙고 게임
 * 5개의 줄이 다 그어져야하고, 이 줄이 세 개일때 빙고를 외친다.
 * 사회작 몇 번째 수를 부른 후 빙고를 외치게 되는지 출력
 * 숫자는 1부터 25이다.
 *
 *
 *
 * 1. 입력을 받는다.
 * 2. visited 배열을 만든다.
 * 3. 사회자가 부를 때마다 visited를 체크한다. 사회자가 부른 횟수도 카운트한다.
 * 4. 행, 열을 순회한다. 모두 visited일때 빙고 cnt++
 * 5. 좌표의 값이 x+y == 4 일때 혹은(0,0) (1,1) (2,2) (3,3) x-y == 0 일때
 * 검사한다. 왼쪽 대각선 오른쪽 대각선을 검사한다.
 *  행 -> 열 -> (조건 만족시 ) 왼쪽 대각선 -> 오른쪽 대각선
 * 빙고가 아니라면 종료하고 다시 탐색한다.

 *
 *
 * 1시간 : 코드 개더러움 이거 아닌것 같아 빽
 * 근데 구현은 원래 그런듯 블로그 찾아보니 다른 사람들도 그럼
 * 근데 이상하게 뜨길래 문제 다시 시뮬레이션 하고 디버깅하는데 30분
 *
 * 종이로 적어보기 5분
 * 25분 디버깅
 * \ / if 조건문을 반대로 둔 거였음
 *
 *
 */

int board[MAX][MAX];
int ans[MAX][MAX];

int bingo, cnt;

void checkRow(int row) {
  bool flag = true;
  for (int i = 0; i < MAX; i++) {
    // 하나라도 0이 아니라면 종료한다.
    if (board[row][i] != 0) {
      flag = false;
      break;
    }
  }

  if (flag) bingo++;
  return;
}

void chcekCol(int col) {
  bool flag = true;
  for (int i = 0; i < MAX; i++) {
    // 하나라도 0이 아니라면 종료한다.
    if (board[i][col] != 0) {
      flag = false;
      break;
    }
  }
  if (flag) bingo++;
  return;
}

//  \ 열 검사
void checkUpLeftToDownRight(int row, int col) {
  bool flag = true;
  if (row == col) {
    for (int i = 0; i < MAX; i++) {
      if (board[i][i] != 0) {
        flag = false;
        return;
      }
    }
  } else {
    return;
  }

  if (flag) bingo++;
  return;
}

void checkUpRightToDownLeft(int row, int col) {
  bool flag = true;

  if ((row + col) == 4) {
    for (int i = 0; i < MAX; i++) {
      if (board[i][MAX - i - 1] != 0) {
        flag = false;
        return;
      }
    }
  } else {
    return;
  }

  if (flag) bingo++;
  return;
}

// 방문시 0을 쓰자

void check(int row, int col) {
  checkRow(row);
  if (bingo >= 3) return;
  chcekCol(col);
  if (bingo >= 3) return;
  checkUpLeftToDownRight(row, col);
  if (bingo >= 3) return;
  checkUpRightToDownLeft(row, col);
  if (bingo >= 3) return;
}

int findAns(int ans) {
  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      if (board[row][col] == ans) {
        // 0이 들어갈 일이 없으니까.
        board[row][col] = 0;
        cnt++;

        // cout << "들어가기 전 좌표" << row << " " << col;
        check(row, col);

        if (bingo >= 3) {
          return 1;
        }
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      cin >> board[row][col];
    }
  }

  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      cin >> ans[row][col];
    }
  }

  // MAX만큼 불렀을때마다 검사한다.
  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      if (findAns(ans[row][col])) {
        cout << cnt;
        return 0;
      };
    };
  }
  return 0;
}
