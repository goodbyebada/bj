const n = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim();

function makeStarWithMap(num) {
  const size = 4 * (num - 1) + 1;
  // 패턴의 전체 크기

  const grid = Array.from({ length: size }, () => Array(size).fill(" "));
  // 전체 그리드 초기화
  // size * size

  for (let i = 0; i < num; i++) {
    const start = 2 * i;
    // 현재 단계의 시작 지점

    const end = size - 1 - 2 * i;

    // 현재 단계의 끝 지점
    // size -1 끝단계
    // size -1, size-1-2, size-1-3 ```

    // 위쪽과 아래쪽 테두리
    for (let j = start; j <= end; j++) {
      grid[start][j] = "*";
      // 위쪽
      grid[end][j] = "*";
      // 아래쪽
    }

    // 왼쪽과 오른쪽 테두리
    for (let j = start; j <= end; j++) {
      grid[j][start] = "*";
      // 왼쪽
      grid[j][end] = "*";
      // 오른쪽
    }
  }

  // 출력
  console.log(grid.map((row) => row.join("")).join("\n"));
}

makeStarWithMap(Number(n));
