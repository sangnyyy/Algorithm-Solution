//
// Created by SML on 2018. 9. 18..
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[21][21];
bool d[21];
int ans = 987654321;
int n;

void dfs(int idx, int cnt) {
    if (cnt == (n/2)) {
        vector<int> start;
        vector<int> link;
        for (int i = 1; i <= n; ++i) {
            if(d[i]) start.push_back(i);
            else link.push_back(i);
        }
        int temp1 = 0, temp2 = 0, ret;
        for (int i = 0; i < start.size()-1; ++i) {
            for (int j = i+1; j < start.size(); ++j) {
                temp1 += a[start[i]][start[j]] + a[start[j]][start[i]];
            }
        }
        for (int i = 0; i < link.size()-1; ++i) {
            for (int j = i+1; j < link.size(); ++j) {
                temp2 += a[link[i]][link[j]] + a[link[j]][link[i]];
            }
        }

        ret = (temp1 - temp2);
        ret = ret > 0 ? ret : ret*(-1);
        ans = min(ret, ans);
        return;
    }
    for (int i = idx+1; i <= n; ++i) {
        if(!d[i]){
            d[i] = true;
            dfs(i, cnt + 1);
            d[i] = false;
        }
    }

}


int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << '\n';
    return 0;
}