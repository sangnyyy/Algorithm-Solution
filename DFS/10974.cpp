//
// Created by Administrator on 2018-09-17.
//

#include <iostream>

using namespace std;

int d[9];
int n;

void dfs(int num, int depth) {
    d[depth] = num;
    if (depth == n) {
        for (int i = 1; i <= depth; ++i) {
            cout << d[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        bool inArray = false;
        for (int j = 1; j <= depth; ++j) {
            if (d[j] == i) inArray = true;
        }
        if(!inArray){
            dfs(i, depth + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        dfs(i,1);
    }
    return 0;
}