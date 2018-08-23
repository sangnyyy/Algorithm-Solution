# DFS, BFS

## 12851 - 숨바꼭질2

n = 1, k = 3이라고 가정했을 때, 최단시간의 경우의 수는 1X2+1, 1+1+1로 2가지가 된다. 나는 기존에 큐에 push를 하면서 방문여부를 체크했는데 이렇게 구현하게 되면 1+1에서 방문으로 체크된 경우가 1X2의 조건에서 큐에 들어가지 않기 때문에 경우의 수를 잡아 낼 수가 없게 된다. 따라서 큐에서 front를 pop하면서 방문여부를 true로 해주게 되면 모든 경우의 수를 잡아 낼 수가 있게 된다.

## 9019 - DSLR

개행을 안해줘서 틀리는 아주 사소한 부분의 문제였지만 많은 것을 배울 수 있었던 문제이다.

* 숫자를 왼쪽으로 한칸씩 이동(4자리수)

```C
int left = (n%1000)*10 + n/1000;
```

* 숫자를 오른쪽으로 한칸씩 이동(4자리수)

```C
int right = (n/10) + (n%10)*1000;
```