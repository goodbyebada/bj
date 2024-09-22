#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[5000];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  int now = 0;

  printf("<");
  while (n != 1) {
    now += k - 1;
    // targetIndex 설정

    if (now >= n) now %= n;
    // size를 넘긴다면 모듈러로 재설정
    printf("%d, ", arr[now]);
    // target 출력

    // now+1 -> targetIndex의 다음 인덱스
    for (int i = now + 1; i < n; i++) {
      arr[i - 1] = arr[i];
      // 배열의 값을 바꾼다.
      //   한칸씩 val을 땡긴다.
    }
    n--;
    // 길이를 줄인다.
  }

  //   배열의 길이가 1이라면 마지막 원소를 print한다.
  printf("%d>", arr[0]);

  return 0;
}