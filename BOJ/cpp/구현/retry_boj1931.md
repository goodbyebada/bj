# BOJ1931 달팽이

처음 생각한 아이디어로 다시 풀어봤다.

**처음 아이디어**

1. 중앙점부터 시작한다.
2. 중앙점 `{startX, startY}`에서 startX-1 한 상태에서 순회를 시작한다.
3. 각 순회는 level에 따라 2\*level만큼 반복한다.
   - level은 1부터 시작한다.
   - `startX == 0 && startY == 0` 이면 종료한다.

```cpp

for(int i = 0 ; i < 4; i++){
	for(int j = 0; j < 2*level; j++){
		startX += dx[dir];
     	startY += dy[dir];
	}
}

level++;
```

처음에 생각한 방법이다.
i는 방향 배열 dx,dy를 가리키는 index이다.
cnt(N/2)를 정해서 while문을 돌렸는데 bus error가 났다.
`다시 복기해보자`

**알게 된 점 아이디어**

1. 전체 횟수만큼 for문을 돌린다. dir에 대한 idx는 (dir+1)%4 를 통해 idx를 움직일 수 있다.
2. 방향에 대한 일관성을 유지한다면 덜 헷갈린다.
   - `우 아래 좌 위` 순서를 유지하기 위해 `startX-1`, `startY-1` 부터 시작한다.
3. findNum이 1일때에 대한 처리가 없었다. 예외케이스를 조심하자.
4. level(바퀴)가 높아질때마다 거리가 2씩 멀어진다.
