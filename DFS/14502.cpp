//
// Created by SML on 2018. 9. 15..
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
int a[9][9];
int cp[9][9];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void mapCopy(){
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cp[i][j] = a[i][j];
        }
    }
}


void bfs(){
    int temp[9][9];
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            temp[i][j] = cp[i][j];
        }
    }
    queue<int> qx;
    queue<int> qy;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(temp[i][j] == 2){
                qx.push(j);
                qy.push(i);
                while(!qx.empty()){
                    int tx = qx.front();
                    int ty = qy.front();
                    qx.pop(); qy.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = tx + dx[k];
                        int ny = ty + dy[k];
                        if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
                        if(!temp[ny][nx]){
                            temp[ny][nx] = 2;
                            qx.push(nx); qy.push(ny);
                        }
                    }
                }
            }
        }
    }
    int tempNum = 0;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(!temp[i][j]) tempNum++;
        }
    }
    ans = max(tempNum, ans);
}



void dfs(int count){
    if(count == 2) {
        bfs();

        return;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(!cp[i][j]){
                cp[i][j] = 1;
                dfs(count + 1);
                cp[i][j] = 0;
            }
        }
    }
 }

int main(){
    cin >> n >> m;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            mapCopy();
            if(!a[i][j]){
                mapCopy();
                cp[i][j] = 1;
                dfs(0);
                cp[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}