//
// Created by SML on 2018. 9. 27..
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;
int n, MAX;

int main() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    do {
        int result = 0;
        for (int i = 0; i < n-1; ++i) {
            result += abs(v[i] - v[i+1]);
        }
        MAX = max (MAX, result);
    } while (next_permutation(v.begin(), v.end()));
    cout << MAX << '\n';
    return 0;
}