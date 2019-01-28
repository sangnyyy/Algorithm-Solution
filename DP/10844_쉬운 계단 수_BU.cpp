//
// Created by SML on 1/28/19.
//

#include <iostream>

#define MOD 1000000000
using namespace std;

int n, ans;
int d[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= 9; ++i) {
        d[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                d[i][j] = d[i - 1][j + 1];
            } else if (j == 9) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1]) % MOD;
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        ans += d[n][i] % MOD;
        ans = ans % MOD;
    }
    cout << ans << '\n';
    return 0;
}