# Dynamic Programming

## 1520 - 내리막길

계속해서 시간초과가 났는데 그 이유가 memoization을 -1로 안해서 그러함. memoization을 0으로 초기화했을때의 문제는 배열의 특정위치에서 이게 0인 이유가 처음 방문해서 0인건지 경로가 없어서 0인건지 구별이 안되서임. 따라서, 이 부분문제를 반복적으로 풀게되기 때문에 시간초과가 난다.

```C
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int go(int x, int y){
	if (x == 0 && y == 0) return 1;
	if (d[x][y] > 0) return d[x][y];
    for (int k = 0; k<4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m){
			if (a[nx][ny] > a[x][y]){
				d[x][y] += go(nx, ny);
			}
		}
	}
	return d[x][y];
}

```

## 2193 - 이친수

입력 N의 범위는 1 ~ 90인데 피보나치 점화식 90번은 그 횟수가 int의 범위를 넘어가므로 long long타입으로 해야한다.