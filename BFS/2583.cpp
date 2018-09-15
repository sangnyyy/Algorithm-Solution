//
// Created by SML on 2018. 8. 27..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool a[101][101];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main(){
    int n, m, k, ans = 0;
    vector<int> v;
    cin >> n >> m >>k;
    for (int i = 0; i < k; ++i) {
        int lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;
        for (int j = ly; j < hy; ++j) {
            for (int l = lx; l < hx; ++l) {
                a[j+1][l+1] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(a[i][j]) continue;
            queue<int> qy;
            queue<int> qx;
            a[i][j] = true;
            qy.push(i);
            qx.push(j);
            int temp = 1;
            while(!qx.empty()){
                int tempY = qy.front();
                int tempX = qx.front();
                qy.pop(); qx.pop();
                for (int l = 0; l < 4; ++l) {
                    if(tempX + dx[l] < 1 || tempY + dy[l] < 1 || tempX + dx[l] > m || tempY + dy[l] > n) continue;
                    if(!a[tempY + dy[l]][tempX + dx[l]]){
                        a[tempY + dy[l]][tempX + dx[l]] = true;
                        qy.push(tempY + dy[l]); qx.push(tempX + dx[l]);
                        temp++;
                    }
                }
            }
            v.push_back(temp);
            ans++;
        }
    }

    cout << ans << '\n';
    sort(v.begin(), v.end());
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}