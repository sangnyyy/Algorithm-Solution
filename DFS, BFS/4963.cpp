//
// Created by SML on 2018. 8. 29..
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dx[] = {-1, 1,0, 0, 1, -1 ,1, -1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

int a[51][51];

int main(){
    while(true){
        int w, h, ans = 0;
        queue<int> qx;
        queue<int> qy;
        cin >> w >> h;
        if(w==0&&h==0) break;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w ; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w ; ++j) {
                if(a[i][j]){
                    ans++;
                    a[i][j] = 0;
                    qx.push(j);
                    qy.push(i);
                    while(!qx.empty()){
                        int tx = qx.front();
                        int ty = qy.front();
                        qx.pop(); qy.pop();
                        for (int k = 0; k < 8; ++k) {
                            if(tx+dx[k] < 1 || tx+dx[k]>w || ty+dy[k] < 1 || ty+dy[k]>h) continue;
                            if(a[ty+dy[k]][tx+dx[k]]) {
                                a[ty + dy[k]][tx + dx[k]] = 0;
                                qx.push(tx + dx[k]);
                                qy.push(ty + dy[k]);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}