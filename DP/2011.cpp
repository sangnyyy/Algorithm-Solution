//
// Created by SML on 2018. 10. 2..
//

#include <iostream>
#include <string>
#include <cstring>
#define MOD 1000000
using namespace std;

bool isWrong = false;
int a[5001];
int d[5001];

int go(int num){
    if(num == 0) return 1;
    if(d[num] > 0) return d[num];
    if(a[num] != 0){
        d[num] += go(num-1)%MOD;
        int temp = a[num-1]*10 + a[num];
        if(temp >= 11 && temp <= 26) d[num] += go(num-2)%MOD;
    }else{
        if(a[num-1] == 1 || a[num-1] == 2) d[num] = go(num-2)%MOD;
    }
    return d[num];
}

int main(){

    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        a[i+1] = s[i] - '0';
    }
    if(a[1] == 0) {
        cout << 0 << '\n';
    }else{
        for (int i = 1; i <= n-1; ++i) {
            if(a[i] >= 3 && a[i+1] == 0) isWrong = true;
        }
        if(!isWrong){
            cout << go(n)%MOD;
        }else{
            cout << 0 << '\n';
        }
    }
    return 0;
}