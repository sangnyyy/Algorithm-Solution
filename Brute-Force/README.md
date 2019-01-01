# Dynamic Programming

## 15649 - N과 M (1)

다음과 같이 Vector의 모든 원소를 확인하여 다음 삽입 원소를 파악했는데 이러면 for문이 한번 더 돌게 됨..
```C
for (int i = 1; i <= n; ++i) {
        bool inVector = false;
        for (int j = 0; j < v.size(); ++j) {
            if (i == v[j]) inVector = true;
        }
        if (!inVector) {
            v.push_back(i);
            dfs(count + 1);
            v.pop_back();
        }
    }
```

따라서 다음과 같이 개선

```C
bool useNum[9]; // 원소를 사용했는지 기록

if(useNum[i]) continue; // 원소를 사용했다면 dfs 생략
```

위와같이 하면 매번 vector의 내용물을 확인하지 않아도 됨.

## 15663 - N과 M (9)

각각의 원소들에 대해 저장하는 2차원 벡터를 생성해야 한다.

```C
vector<vector<int>> vv;
```

2차원 벡터 또한 <i><strong>sort 함수</strong></i>를 먹는다.
내용물인 1차원 int형 vector를 기준으로 정렬한다.
```c
//예를들어
sort(vv.begin(), vv.end());
```

resize() 함수와 unique() 함수를 이용하여 중복 값을 제거한다.

```C
vv.resize(unique(vv.begin(), vv.end()) - v.begin());
```