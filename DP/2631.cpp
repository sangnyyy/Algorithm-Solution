//
// Created by SML on 1/3/19.
//

#include <iostream>
#include <algorithm>
using namespace std;
int child[201];
int d[201];
int n, lis;

int dp(int n){
    if(n == 1) return 1;
    if(d[n] > 0) return d[n];
    d[n] = 1;
    for (int i = 1; i < n; ++i) {
        if(child[i] < child[n]) {
            int temp = dp(i) + 1;
            if(d[n] < temp) d[n] = temp;
        }
    }
    return d[n];
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> child[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp(i);
    }
    for (int i = 1; i <= n; ++i) {
        if(lis < d[i]) lis = d[i];
    }
    int ans = n-lis;
    cout << ans << '\n';
    return 0;
}