//
// Created by SML on 2018. 10. 10..
//

#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;

int a[1001][1001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        a[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j]) {
                ans++;
                a[i][j] = 0;
                a[j][i] = 0;
                q.push(j);
                while(!q.empty()){
                    int now = q.front();
                    q.pop();
                    for (int k = 1; k <= n; ++k) {
                        if(a[now][k]) {
                            a[now][k] = 0;
                            a[k][now] = 0;
                            q.push(k);
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}