function main() {
  const keyboard = `qwertyuiop
asdfghjkl
zxcvbnm`
    .split("\n")
    .map((row, i) => row.split("").reduce((map, char, j) => {
      map[char] = [i, j];
      return map;
    }, {}))
    .reduce((acc, cur) => Object.assign(acc, cur), {});

  const input = require("fs")
    .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./text.txt")
    .toString()
    .trim()
    .split("\n");

  const [leftChar, rightChar] = input[0].split(" ");
  const str = input[1];

  let leftPos = keyboard[leftChar];
  let rightPos = keyboard[rightChar];
  let moveCnt = 0;

  const isLeftHand = (char) => "qwertasdfgzxcv".includes(char);

  for (const char of str) {
    const newPos = keyboard[char];

    if (isLeftHand(char)) {
      moveCnt += Math.abs(leftPos[0] - newPos[0]) + Math.abs(leftPos[1] - newPos[1]);
      leftPos = newPos;
    } else {
      moveCnt += Math.abs(rightPos[0] - newPos[0]) + Math.abs(rightPos[1] - newPos[1]);
      rightPos = newPos;
    }

    moveCnt++; // 키를 누르는 시간 추가
  }

  console.log(moveCnt);
}

main();
