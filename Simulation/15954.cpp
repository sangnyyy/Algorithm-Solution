//
// Created by SML on 1/25/19.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define INF 0x3f3f3f3f
using namespace std;

int n, k;
double ans;
int toy[501];

int main() {
    ans = INF;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> toy[i];
    }
    while (k <= n) {
        for (int i = 1; i + k - 1 <= n; ++i) {
            double series = 0;
            double m, bunsan;
            m = bunsan = 0;
            for (int j = i; j <= i + k - 1; ++j) {
                series += toy[j];
            }
            m += series;
            m /= k;
            for (int j = i; j <= i + k - 1; ++j) {
                bunsan += pow((toy[j] - m), 2);
            }
            bunsan /= k;
            bunsan = sqrt(bunsan);
            ans = min(ans, bunsan);
        }
        k++;
    }
    cout.precision(11);
    cout << ans << '\n';
    return 0;
}