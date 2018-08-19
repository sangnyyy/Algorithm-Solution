//
// Created by SML on 2018. 8. 17..
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[1001][10];

int go(int n, int m){
    if(n == 1) return 1;
    if(d[n][m] > 0) return d[n][m];
    d[n][m] = 0;
    for(int i =0; i <= m; i++){
        d[n][m] += (go(n-1, i) % 10007);
    }
    return d[n][m];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < 10 ; ++i) {
        sum += (go(n, i) % 10007);
    }

    cout << sum % 10007 << '\n';

    return 0;
}