//
// Created by SML on 2018. 9. 2..
//

#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int a[1001];

int go(int n){
    if(n == 1) return a[1];
    if(d[n] > 0) return d[n];
    d[n] = a[n];
    for (int i = n-1; i > 0 ; --i) {
        if(a[n] > a[i]) {
            int temp = go(i) + a[n];
            if(temp > d[n]) d[n] = temp;
        }
    }
    return d[n];
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int MAX = 0;
    for (int i = 1; i <= n; ++i) {
        MAX = max(go(i), MAX);
    }

    cout << MAX <<'\n';
    return 0;
}