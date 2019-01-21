//
// Created by SML on 1/21/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define X 6
#define Y 12

using namespace std;

class elem {
public:
    int x, y;
    elem(int x, int y) : x(x), y(y) {}
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

char field[Y + 1][X + 1];
bool visit[Y + 1][X + 1];

int ans;
bool restart;

bool comp(elem a, elem b) {
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

void dfs(int x, int y, char c, vector<elem> &v) {
    int nextX, nextY;
    for (int i = 0; i <= 3; ++i) {
        nextX = x + dx[i];
        nextY = y + dy[i];
        if (nextX < 1 || nextX > X || nextY < 1 || nextY > Y) continue;
        if ((field[nextY][nextX] == c) && !visit[nextY][nextX]) {
            v.push_back(elem(nextX, nextY));
            visit[nextY][nextX] = true;
            dfs(nextX, nextY, c, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    for (int i = 1; i <= Y; ++i) {
        for (int j = 1; j <= X; ++j) {
            cin >> field[i][j];
        }
    }
    do {
        restart = false;
        vector<elem> v;
        for (int i = 1; i <= Y; ++i) {
            for (int j = 1; j <= X; ++j) {
                if (field[i][j] != '.' && !visit[i][j]) {
                    vector<elem> tempV;
                    visit[i][j] = true;
                    tempV.push_back(elem(j, i));
                    for (int k = 0; k <= 3; ++k) {
                        int nextX = j + dx[k], nextY = i + dy[k];
                        if (nextX < 1 || nextX > X || nextY < 1 || nextY > Y) continue;
                        if ((field[i][j] == field[nextY][nextX]) && !visit[nextY][nextX]) {
                            visit[nextY][nextX] = true;
                            tempV.push_back(elem(nextX, nextY));
                            dfs(nextX, nextY, field[i][j], tempV);
                        }
                    }
                    int vSize = tempV.size();
                    if (vSize > 3) {
                        for (int k = vSize - 1; k >= 0; --k) {
                            v.push_back(elem(tempV[k].x, tempV[k].y));
                        }
                    }else{
                        for (int k = vSize - 1; k >= 0; --k) {
                            visit[tempV[k].y][tempV[k].x] = false;
                        }
                    }
                }
            }
        }
        if(!v.empty()){
            int idx = v.size();
            restart = true;
            ans++;
            sort(v.begin(), v.end(), comp);
            for (int i = 0; i < idx; ++i) {
                int tempX = v[i].x, tempY = v[i].y;
                for (int j = tempY; j > 1; --j) {
                    field[j][tempX] = field[j-1][tempX];
                }
                field[1][tempX] = '.';
            }
            for (int i = 0; i < idx; ++i) {
                visit[v[i].y][v[i].x] = false;
            }
        }
    } while (restart);

    cout << ans << '\n';
    return 0;
}