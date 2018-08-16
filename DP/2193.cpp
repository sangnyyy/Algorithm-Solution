//
// Created by SML on 2018. 8. 16..
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long d[91][2];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    d[1][0] = 0; d[1][1] = 1;

    for (int i = 2; i <= n; ++i) {
        d[i][1] += d[i-1][0];
        d[i][0] += d[i-1][0] + d[i-1][1];
    }

    cout << d[n][0] + d[n][1] << '\n';
    return 0;
}