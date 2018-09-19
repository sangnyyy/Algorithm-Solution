//
// Created by SML on 2018. 9. 18..
//

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n, f, s, rel;

bool r[101][101];
bool node[101];


int main() {
    bool tf = false;
    cin >> n >> f >> s >> rel;
    queue<pair<int, int>> q;
    for (int i = 1; i <= rel; ++i) {
        int tx, ty;
        cin >> tx >> ty;
        r[ty][tx] = true;
        r[tx][ty] = true;
    }
    node[f] = true;
    q.push(make_pair(f, 0));
    while (!q.empty()) {
        int now = q.front().first;
        int count = q.front().second;
        q.pop();
        if (now == s) {
            tf = true;
            printf("%d\n", count);
        }
        for (int i = 1; i <= n; ++i) {
            if (r[now][i] && (!node[i])) {
                node[i] = true;
                q.push(make_pair(i, count + 1));
            }
        }
    }
    if(!tf){
        cout << -1 <<'\n';
    }

    return 0;
}