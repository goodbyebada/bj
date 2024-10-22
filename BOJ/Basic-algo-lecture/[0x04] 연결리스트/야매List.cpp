#include <algorithm>
#include <iostream>
using namespace std;

const int MX = 10000005;
int dt[MX], pre[MX], nxt[MX];
int unused = 1;

// 연결리스트 모두 출력
void traverse() {
  int cur = nxt[0];
  int initPre = pre[0];

  while (cur != -1) {
    cout << dt[cur] << ' ';
    cur = nxt[cur];
  }

  cout << '\n\n';
}

// unused 사용 x 주소
void insert(int addr, int num) {
  dt[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  // addr 다음 주소가 가리키고 있는 이전 addr를 unused로 변경
  if (nxt[addr] != -1) {
    pre[nxt[addr]] = unused;
  }

  nxt[addr] = unused;
  unused++;
}

// 데이터 건들지 않고 끊기만 하면 된다.
void erase(int addr) {
  int preAddr = pre[addr];
  int nxtAddr = nxt[addr];
  nxt[preAddr] = nxtAddr;

  if (nxt[addr] != -1) {
    pre[nxtAddr] = preAddr;
  }
}

int main(void) {
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
}