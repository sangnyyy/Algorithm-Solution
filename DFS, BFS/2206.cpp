//
// Created by SML on 2018. 8. 29..
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};
int a[1001][1001];
bool visit[1001][1001][2];
int main(){
    int n,m, answer = -1;
    queue<int> qx;
    queue<int> qy;
    queue<int> count;
    queue<int> ans;
    cin >> n >> m;
    for (int i = 1; i <= n ; ++i) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = temp[j-1] - '0';
        }
    }
    qx.push(1);
    qy.push(1);
    count.push(0);
    ans.push(1);
    while(!qx.empty()){
        int tx = qx.front(), ty = qy.front(), tc = count.front(), tans = ans.front();
        qx.pop(); qy.pop(); count.pop(); ans.pop();
        if(tx == m && ty == n){
            if(answer == -1) answer = tans;
            else{
                if(answer > tans) answer = tans;
            }
        }
        for (int i = 0; i < 4; ++i) {
            if(tx + dx[i] < 1 || tx + dx[i] > m || ty+dy[i]<1||ty+dy[i]>n) continue;
            if(!a[ty+dy[i]][tx+dx[i]]){
                if(!visit[ty+dy[i]][tx+dx[i]][tc]) {
                    visit[ty + dy[i]][tx + dx[i]][tc] = true;
                    qx.push(tx + dx[i]);
                    qy.push(ty + dy[i]);
                    count.push(tc);
                    ans.push(tans+1);
                }
            }else{
                if(tc == 0){
                    if(!visit[ty+dy[i]][tx+dx[i]][tc]) {
                        visit[ty + dy[i]][tx + dx[i]][1] = true;
                        qx.push(tx + dx[i]);
                        qy.push(ty + dy[i]);
                        count.push(1);
                        ans.push(tans+1);
                    }
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}