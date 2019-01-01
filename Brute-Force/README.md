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