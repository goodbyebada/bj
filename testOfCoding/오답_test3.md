# Test3 오답

- `segementation fault`가 떠서 풀지 못했다.

**이유**

1. 재귀로 풀었었는데, 순서를 바꾼 같은 갯수의 덱을 인자로 받아서 무한 루프를 돌아 `segementation fault`의 원인이 됐다. 애초에 로직도 틀렸다. n장의 카드를 제거한 카드를 넘겨야 무한루프를 안 돈다. 그렇게 될 시 제거한 n개의 카드 정보는 알 수 없다.
   재거했던 n개의 카드 정보를 넣는 로직을 넣었야한다.

2.size_t는 unsigned이다.

```cpp
  if (originDeque.size() - (2 * n) <= 0) {
    break;
  }

```

`originDeque.size() - (2 * n)` unsigned 이기 때문에 위 if문을 만족하지 못해 while문을 탈출 못한다. 하지만 originDeque은 계속 길이가 줄어들고 있기 때문에 for문에서 유효하지 않은 idx에 접근하려고 한다. 때문에 위와 같은 에러가 발생한다.

**틀린 로직**

1 2 3 4 5 6 7 8 9 10
이 있다면

5 6 3 4 7 8 1 2 9 10
이 되어야한다.

하지만 push_back을 통해서

5 6 1 2 9 10 3 4 7 8
로 계산되었다.

10 9 2 1
순으로 push_front로 접근해야한다.
