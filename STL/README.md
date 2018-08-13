# C++ STL

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