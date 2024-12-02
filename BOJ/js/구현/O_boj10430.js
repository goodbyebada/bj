const fs = require("fs");

/**
 * 나머지
 * 브론즈 5
 *
 *
 */

const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ");

function main() {
  const [a, b, c] = input.map(Number);
  // 첫째줄
  const setFirst = (a + b) % c;

  // js 특 string끼리 사칙연산됨

  const setSecond = ((a % c) + (b % c)) % c;
  const setThird = (a * b) % c;
  const setFour = ((a % c) * (b % c)) % c;

  console.log(setFirst);
  console.log(setSecond);
  console.log(setThird);
  console.log(setFour);
  return;
}

main();
