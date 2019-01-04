//
// Created by SML on 1/4/19.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

#define INF 0x3f3f3f3f
using namespace std;

int miro[101][101];
bool visit[101][101];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class node {
public:
    int x, y;

    node(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<node> v[10001];

int n, ans;

int main() {
    ios::sync_with_stdio(0);
    ans = INF;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> miro[i][j];
        }
    }
    int area = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (miro[i][j] > 0 && !visit[i][j]) {
                queue<node> q;
                q.push(node(j, i));
                v[area].push_back(node(j, i));
                visit[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().x, y = q.front().y; q.pop();
                    for (int k = 0; k <= 3; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > n ||
                        miro[ny][nx] == 0 || visit[ny][nx]) continue;
                            q.push(node(nx, ny));
                            v[area].push_back(node(nx, ny));
                            visit[ny][nx] = true;
                    }
                }
                area++;
            }
        }
    }

    for (int i = 1; i < area; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            for (int k = i + 1; k < area; ++k) {
                for (int l = 0; l < v[k].size(); ++l) {
                    int distx = abs((v[i])[j].x - (v[k])[l].x);
                    int disty = abs((v[i])[j].y - (v[k])[l].y);
                    int res = distx + disty - 1;
                    ans = min(ans, res);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}