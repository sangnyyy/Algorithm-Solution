//
// Created by SML on 2018. 10. 9..
//

#include <iostream>
#include <queue>

using namespace std;

int a[51];
int ans;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int num, lCount, rCount, idx;
        cin >> num;
        for (int j = 1; j <= n; ++j) {
            if (a[j] == num) {
                idx = j;
                break;
            }
        }
        lCount = idx - 1;
        rCount = n - idx + 1;
        if (lCount < rCount) {
            while (lCount != 0) {
                int first = a[1];
                for (int j = 1; j <= n - 1; ++j) {
                    a[j] = a[j + 1];
                }
                a[n] = first;
                lCount--;
                ans++;
            }
            for (int j = 1; j <= n - 1; ++j) {
                a[j] = a[j + 1];
            }
        } else {
            while (rCount != 0) {
                int last = a[n];
                for (int j = n - 1; j >= 1; --j) {
                    a[j + 1] = a[j];
                }
                a[1] = last;
                rCount--;
                ans++;
            }
            for (int j = 1; j <= n - 1; ++j) {
                a[j] = a[j + 1];
            }

        }
        n--;
    }

    cout << ans << '\n';
    return 0;
}