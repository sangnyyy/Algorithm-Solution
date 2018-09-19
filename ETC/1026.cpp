//
// Created by SML on 2018. 9. 19..
//

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
int n;
int a[51];
int b[51];

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<int>());

    for (int i = 1; i <= n; ++i) {
        ans += (a[i] * b[i]);
    }
    cout << ans << '\n';
    return 0;
}