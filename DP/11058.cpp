//
// Created by SML on 2018. 8. 27..
//
#include <iostream>
#include <algorithm>
long long d[101]; //출력 할 수 있는 A의 최대 갯수

// 0, 1, 2, 3 - 출력, 전체, 복사, 복사내용 출력

using namespace std;
int main(){
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    for (int i = 4; i <= n ; ++i) {
        long long temp = d[i-1] + 1;
        for (int j = 3; i-j >= 1; ++j) {
            if(temp < (d[i-j]*(j-1))){
                temp = d[i-j]*(j-1);
            }
        }
        d[i] = temp;
    }
    cout<< d[n] << '\n';
    return 0;
}