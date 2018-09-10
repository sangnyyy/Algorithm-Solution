//
// Created by SML on 2018. 9. 10..
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dx[] = {-1, -2, -1, -2, 1, 2, 1,2};
const int dy[] = {-2, -1, 2, 1, -2, -1, 2, 1};
bool v[301][301];

int main(){
    int t;
    cin >> t;
    while(t){
        memset(v, false, sizeof(v));
        bool isVisit = false;
        int l, nx, ny, fx, fy;
        cin >> l;
        cin >> nx >> ny >> fx >> fy;
        queue<int> qx; queue<int> qy; queue<int> qc;
        v[ny][nx] = true;
        qx.push(nx);
        qy.push(ny);
        qc.push(0);
        while(!qx.empty()){
            int tx, ty, tc;
            tx = qx.front();
            ty = qy.front();
            tc = qc.front();
            if(tx == fx && ty == fy){
                isVisit = true;
                cout << tc << '\n';
            }
            qx.pop(); qy.pop(); qc.pop();
            for (int i = 0; i < 8; ++i) {
                if(tx + dx[i] < 0 || tx + dx[i] >= l || ty + dy[i] < 0 || ty + dy[i] >= l) continue;
                if(!v[ty + dy[i]][tx + dx[i]]) {
                    v[ty + dy[i]][tx + dx[i]] = true;
                    qx.push(tx + dx[i]);
                    qy.push(ty + dy[i]);
                    qc.push(tc+1);
                }
            }
        }
        if(!isVisit){
            cout << 0 << '\n';
        }
        t--;
    }
    return 0;
}