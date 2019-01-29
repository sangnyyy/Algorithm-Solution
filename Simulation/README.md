# Simulation 혹은 구현

## 16235 - 나무 재테크

느낀점, vector 사용 시 erase를 왠만하면 사용하지 말자.

```C
vector<int> vec;
for ( vector<int>::size_type i=0; i < vec.size(); ) {
    if (삭제의 조건문) {
        vec.erase(vec.begin() + i);
    }
    else {
        i++;
    }
}
```
> erase 함수 실행 시 배열의 뒷요소들이 자동으로 앞으로 당겨짐. 따라서, erase함수가 실행되지 않는 경우에만 인덱스를 증가시키게 해야함.

출처: https://backhugger.tistory.com/45 [BROKENCAPSLOCK]