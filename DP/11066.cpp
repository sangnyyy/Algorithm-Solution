//
// Created by SML on 2018. 8. 23..
//

#include <iostream>
#include <cstring>
#define INF 99999999;
using namespace std;

int d[501][501];
int a[501];

int go(int n, int m){
    if(n > m) return 0;
    if(n == m) return 0;
    if(d[n][m] != -1) return d[n][m];
    d[n][m] = INF;
    int num = 0;
    for (int i = n; i <=m ; ++i) {
        num += a[i];
    }
    for (int i = n; i <m ; ++i) {
        int temp = go(n, i) + go(i+1, m) + num;
        if(temp < d[n][m]) d[n][m] = temp;
    }
    return d[n][m];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(d, -1, sizeof(d));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cout << go(1, n) << '\n';
    }
    return 0;
}