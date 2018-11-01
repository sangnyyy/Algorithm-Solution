#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
int arr[21][21];
bool visit[21][21];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class Fish {
public:
    int x;
    int y;
    int time;
};

bool compare(Fish f1, Fish f2) {
    if(f1.time == f2.time){
        if(f1.y == f2. y){
            return f1.x < f2.x;
        }
        return f1.y < f2.y;
    }
    return f1.time < f2.time;
}

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
        // x, y, count
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(startX, startY), 0));
        visit[startY][startX] = true;
        int idx = 0;
        Fish fish[400];
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
                    fish[idx].x = nextX;
                    fish[idx].y = nextY;
                    fish[idx].time = time + 1;
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
            sort(fish, fish + idx, compare);
            ans += fish[0].time;
            startX = fish[0].x;
            startY = fish[0].y;
            arr[startY][startX] = 0;
            if ((++eating) == shark) {
                shark++;
                eating = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
