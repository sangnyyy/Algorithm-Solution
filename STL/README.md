# C++ STL

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