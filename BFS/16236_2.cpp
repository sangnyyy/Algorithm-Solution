#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int n, ans;
int arr[21][21];
int dist[21][21];
bool visit[21][21];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int shark = 2, eating = 0;
    int startX, startY;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                startY = i;
                startX = j;
                arr[i][j] = 0;
            }
        }
    }
    while (true) {
        memset(visit, false, sizeof(visit));
        memset(dist, INF, sizeof(dist));
        // x, y, count
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(startX, startY), 0));
        visit[startY][startX] = true;
        int idx = 0;
        while (!q.empty()) {
            int nowX, nowY, time;
            nowX = q.front().first.first;
            nowY = q.front().first.second;
            time = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nextX, nextY;
                nextX = nowX + dx[i];
                nextY = nowY + dy[i];
                if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                // 먹을 수 있는 물고기들
                if ((arr[nextY][nextX] > 0 && arr[nextY][nextX] < shark) && (!visit[nextY][nextX])) {
                    if(dist[nextY][nextX] > time+1) dist[nextY][nextX] = time+1;
                    idx++;
                    visit[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextX, nextY), time + 1));
                }
                if ((arr[nextY][nextX] == 0 || arr[nextY][nextX] == shark) && (!visit[nextY][nextX])) {
                    visit[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextX, nextY), time + 1));
                }
            }
        }
        if (idx == 0) break;
        else {
            int tempMIN = INF;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if(tempMIN > dist[i][j]){
                        tempMIN = dist[i][j];
                        startX = j;
                        startY = i;
                    }
                }
            }
            arr[startY][startX] = 0;
            if((++eating) == shark){
                shark++; eating = 0;
            }
            ans += tempMIN;
        }
    }
    cout << ans << '\n';
    return 0;
}
