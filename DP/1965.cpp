//
// Created by SML on 1/3/19.
//

#include <iostream>

using namespace std;

int box[1001];
int d[1001];
int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> box[i];
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (box[j] < box[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
        }
        if(ans < d[i]) ans = d[i];
    }
    cout << ans << '\n';
    return 0;
}