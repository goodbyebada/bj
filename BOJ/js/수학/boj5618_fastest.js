/**
 *가장 작은 수의 약수를 구하고 (공약수의 후보가 가장 적음)
 Sqrt(arr[0])만큼 순회해 공약수가 아닌 후보를 제거한다. 
 또한 set을 이용하여 중복된 값을 방지할 수 있다.
 때문에 내가 짠 코드보다 빠르다

 */

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./text.txt")
  .toString()
  .trim()
  .split("\n");

const N = Number(input[0]);

// 가장 작은 값을 소인수분해한다.

const arr = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);

//   중복된 값 방지
let result = new Set();

// 주어진 수의 절반 이상으로 mod 하기
// 가장 작은 값의 약수를 구한다. => 약수의 개수가 적으니까
for (let i = 1; i * i <= arr[0]; i++) {
  if (arr[0] % i === 0) {
    result.add(i);
    result.add(arr[0] / i);
  }
}

// 이중 for문 N만큼 순회한다.
for (let i = 0; i < N; i++) {
  for (let x of result) {
    // result의 x로 안 나눠지면  공약수가 아니기 때문에 x를 삭제한다.
    if (arr[i] % x) result.delete(x);
  }
}

console.log([...result].sort((a, b) => a - b).join("\n"));
