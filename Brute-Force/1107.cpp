//
// Created by SML on 1/13/19.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#define ORIGIN 100
using namespace std;

int channel, ans;
int buttonCnt;
bool broken[10];

int possible(int n){
    if(n == 0){
        return broken[n] ? 0 : 1;
    }
    int len = 0;
    while(n > 0){
        if(broken[n%10]) return 0;
        len++;
        n /= 10;
    }
    return len;
}

int main(){
    cin >> channel >> buttonCnt;
    for (int i = 0; i < buttonCnt; ++i) {
        int temp; cin >> temp;
        broken[temp] = true;
    }
    ans = abs(channel - ORIGIN);
    for (int j = 0; j <= 1000000; ++j) {
        int len = possible(j);
        if(len > 0){
            ans = min(ans, len + abs(j - channel));
        }
    }
    cout << ans << '\n';
    return 0;
}