//
// Created by SML on 2018. 8. 29..
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int house[525];
int a[26][26];
int main(){
    int n, ans=0; cin >> n;
    queue<int> qx;
    queue<int> qy;
    for (int i = 1; i <= n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j <temp.size() ; ++j) {
            a[i][j+1] = temp[j] - '0';
        }
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            int count = 0;
            if(a[i][j]){
                a[i][j] = 0;
                ans++;
                count++;
                qx.push(j);
                qy.push(i);
                while(!qx.empty()){
                    int tx = qx.front();
                    int ty = qy.front();
                    qx.pop(); qy.pop();
                    for (int k = 0; k < 4; ++k) {
                        if(tx+dx[k] < 1 || tx+dx[k] > n || ty+dy[k] < 1 || ty+dy[k] > n) continue;
                        if(a[ty+dy[k]][tx+dx[k]]){
                            a[ty+dy[k]][tx+dx[k]] = 0;
                            count++;
                            qx.push(tx+dx[k]);
                            qy.push(ty+dy[k]);
                        }
                    }
                }
                house[ans-1] = count;
            }
        }
    }
    cout << ans << '\n';
    sort(house, house + ans);
    for (int i = 0; i < ans; ++i) {
        cout << house[i] << '\n';
    }
    return 0;
}