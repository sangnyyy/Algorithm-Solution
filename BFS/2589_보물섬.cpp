//
// Created by SML on 1/23/20.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char arr[51][51];
bool visit[51][51];
int result;

class pos {
public:
    int y;
    int x;
    int hour;

    pos(int y, int x, int hour) : y(y), x(x), hour(hour) {}
};

queue<pos> q;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int x, y;
    cin >> y >> x;
    for (int i = 1; i <= y; ++i) {
        for (int j = 1; j <= x; ++j) {
            cin >> arr[i][j];
        }
    }


    for (int i = 1; i <= y; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (arr[i][j] == 'L') {
                q.push(pos(i, j, 0));
                visit[i][j] = true;
                while (!q.empty()) {
                    int nowX = q.front().x;
                    int nowY = q.front().y;
                    int hour = q.front().hour;
                    if (result < hour) result = hour;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nextX = nowX + dx[k];
                        int nextY = nowY + dy[k];
                        if (nextX < 1 || nextY < 1 || nextX > x || nextY > y) continue;
                        if (arr[nextY][nextX] == 'L' && !visit[nextY][nextX]) {
                            q.push(pos(nextY, nextX, hour + 1));
                            visit[nextY][nextX] = true;
                        }
                    }
                }
                memset(visit, 0, sizeof(visit));
            }
        }
    }

    cout << result << '\n';


    return 0;
}