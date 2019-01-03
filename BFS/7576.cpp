//
// Created by SML on 1/3/19.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class node {
public:
    int x, y;
    node(int x, int y){
        this->x = x;
        this->y = y;
    }
};

queue<node> q;

int tomato[1001][1001];
int m, n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> tomato[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tomato[i][j] == 1) {
                q.push(node(j, i));
            }
        }
    }
    int qCount = q.size();
    while (!q.empty()) {
        if(qCount == 0) {
            qCount = q.size();
            ans++;
        }
        int x = q.front().x, y = q.front().y; q.pop();
        for (int j = 0; j <= 3; ++j) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (tomato[ny][nx] == 0) {
                tomato[ny][nx] = 1;
                q.push(node(nx, ny));
            }
        }
        qCount--;
    }
    bool noAns = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tomato[i][j] == 0) {
                noAns = true;
                break;
            }
        }
    }
    if (noAns) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}