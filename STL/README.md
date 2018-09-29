## map 함수를 이용한 3차원 원소
* map 라이브러리에 존재
* map 또한 <T, T>의 형태를 가지고 있으며 <Key, Value>라고 생각하면 된다.
* 또한 make_pair()를 이용하여 값을 입력 받는다.
* 또한 map의 첫번째값은 first, 두번째값은 second를 통해 접근
* 3차원 배열을 이용하는 2가지 방법이 있다

    * 첫번째 방법
    ```C
    map<pair<T, T>, T> map;
    ```
    * 두번째 방법
    ```C
    map<T, pair<T, T>> map;
    ```
* count 함수
     ```C
    map<int, int> map;
    map.count(1);   // key 1의 갯수를 반환
    ```


## pair 함수
* utility 라이브러리에 존재
* pair<T, T> 이런 식으로 사용
* make_pair(T, T)를 이용하여 입력 받음.
* pair의 첫번째값은 first, 두번째값은 second를 통해 접근

## sort의 내림차순 정렬
* functional 라이브러리의 greater<T>()를 이용 할 수 있다.
 
 ```c++
#include <functional>
#include <algorithm>
    
sort(시작, 끝, greater<T>());
 ```

## reverse_iterator 사용법
* vecotr의 reverse_iterator 사용법
  
```C
vector<T> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
v.push_back(50);
vector<T>::reverse_iterator rit;
for(rit = v.rbegin(); rit != v.rend(); rit++){
    cout << *rit ;
}
```

## reverse 함수
* algorithm 라이브러리에 존재

```C
reverse(begin, end);
```

## next_permutation 함수
* 현재 원소 이후부터 순열을 구하므로, 모든 원소에 대한 순열을 구하고 싶다면 sort를 한번 해놓고 해야한다!
  
```C
vector<int> v(n);

for(int i =0; i< n; i++){
    cin >> v[i];
}

do{
    for(int i =0; i< n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n'
}while(next_permutation(v.begin(), v.end()));

```

## 2차원 벡터 초기화
* 아래와 같이 초기화 하면 된다.

```C
vector<vector<int>> v(5, vector<int>(6));
for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
        cin >> v[i][j];    
    }
}
```

## String 라이브러리

```C
#include <string>

int find(char c); // char에 해당하는 idx를 반환

string to_string(int num); // num -> string

int stoi(string str); // int -> string
```

