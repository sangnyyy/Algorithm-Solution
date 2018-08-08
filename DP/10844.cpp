#include <iostream>
#define MOD 1000000000;

using namespace std;

int d[101][10];
int go(int n, int m) {
    if (n == 1) {
        return m == 0 ? 0 : 1;
    }
    if (d[n][m] > 0) return d[n][m];
    if(m == 0){ d[n][m] = go(n - 1, 1) % MOD;}
    else if(m == 9){ d[n][m] = go(n - 1, 8) % MOD;}
    else {d[n][m] = (go(n-1,m+1)+go(n - 1, m - 1)) % MOD;}

    return d[n][m];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        sum = (sum+go(n, i)) % MOD;
    }
    sum %= MOD;
    cout << sum << '\n';
    return 0;
}

