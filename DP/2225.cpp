//
// Created by SML on 2018. 8. 23..
//

#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int d[201][201];

int go(int n, int k){
    if(k==0) return n==0?1:0;
    if(d[n][k] != -1) return d[n][k];
    d[n][k] = 0;
    for (int i = 0; i <=n ; ++i) {
        d[n][k] += (go(n-i, k-1));
        d[n][k] %= MOD;
    }
    return d[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;
    memset(d, -1, sizeof(d));
    cout << (go(n, k)%MOD) << '\n';
//    cout << go(n, k) << '\n';
    return 0;
}
