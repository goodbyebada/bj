/**
 * 약수
 * 브론즈 1
 */

function GCD(a, b) {
  let gcdA;
  let gcdB;

  if (a > b) {
    gcdA = a;
    gcdB = b;
  } else {
    gcdA = b;
    gcdB = a;
  }

  while (1) {
    let result = gcdA % gcdB;

    if (result == 0) {
      return gcdB;
    }

    gcdA = gcdB;
    gcdB = result;
  }
}

function LCM(b, a) {
  const gcd = GCD(a, b);
  return (a * b) / gcd;
}

function main() {
  const input = require("fs")
    .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./text.txt")
    .toString()
    .split("\n");

  const numbers = input[1]
    .split(" ")
    .map(Number)
    .sort(function (a, b) {
      return a - b;
    });

  let result = numbers.reduce((acc, curr) => LCM(acc, curr));

  if (result == numbers[numbers.length - 1]) {
    result *= numbers[0];
  }
  console.log(result);
}

main();
