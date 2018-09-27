//
// Created by SML on 2018. 9. 27..
//

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int n, MAX;
int a[9];
int d[9];
int idx[9];
void dfs(int num, int depth) {
    d[depth] = a[num];
    idx[depth] = num;
    if (depth == n) {
        int result = 0;
        for (int i = 1; i <= n - 1; i++) {
            result += abs(d[i] - d[i + 1]);
        }
        MAX = max(MAX, result);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        bool inArr = false;
        for (int j = 1; j <= depth; ++j) {
            if(idx[j] == i) inArr = true;
        }
        if (!inArr) dfs(i, depth + 1);
    }
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i, 1);
    }
    cout << MAX << '\n';

    return 0;
}